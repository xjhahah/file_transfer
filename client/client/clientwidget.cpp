#include "clientwidget.h"
#include "ui_clientwidget.h"

#include "ip_port.hpp"
#include "protocolcommand.h"
#include <QDebug>
#include <QFileDialog>
#include <QDataStream>


ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("客户端"));

    /*文件发送相关初始化*/
    transferData.payloadSize = 4*1024;  //每次发送64kb
    transferData.bytesWritten = 0;
    transferData.bytesToWrite = 0;

    // 设置进度条
    ui->progressBar->setValue(0);
    ui->progressBar->setAlignment(Qt::AlignRight | Qt::AlignVCenter); // 对齐方式
    ui->progressBar->setFormat(QString::fromUtf8("当前无任务：%1%").arg(QString::number(0, 'f', 1)));
}

ClientWidget::~ClientWidget()
{
    delete ui;
}


//设置ip
void ClientWidget::on_ip_lineEdit_editingFinished()
{
    ip_ = ui->ip_lineEdit->text();
    ui->textBrowser->setText(ip_);
    ui->ip_lineEdit->setText(ip_);
}

//设置端口
void ClientWidget::on_port_lineEdit_editingFinished()
{
    port_ = ui->port_lineEdit->text();
    ui->textBrowser->append(port_);
}

//连接
void ClientWidget::on_connectpushButton_clicked()
{
    qDebug()<<ip_;
    qDebug()<<port_;
    if(!if_is_ip(ip_)||!if_is_port(port_)) {
        QMessageBox::about(this, "About", "请输入正确ip或者port！");
    }

    tcpsocket =new QTcpSocket();//创建套接字

    char *str1;
    int port = port_.toInt();
    QByteArray ip = ip_.toLatin1();
    str1 = ip.data();

    tcpsocket->connectToHost(str1,port);

    if(!tcpsocket->waitForConnected(30000))
    {
        qDebug()<<("连接失败");
        ui->textBrowser->append("连接服务器失败");
    }
    else
    {
        qDebug()<<("连接成功");
        ui->textBrowser->append("连接服务器成功");
    }
}

void ClientWidget::sendFile(QString path)
{
    qDebug() << "sockfd send file name: " << path;

    /*初始化发送字节为0*/
    transferData.bytesWritten = 0;

    transferData.localFile = new QFile(path);
    if(!transferData.localFile->open(QFile::ReadOnly))
    {
        qDebug()<<tr("open file error!");
        return;
    }

    //获取文件大小
    transferData.totalBytes = transferData.localFile->size();

    qDebug()<<"发送文件的内容大小: "<<transferData.totalBytes;

    //设置缓冲区
    QDataStream sendOut(&transferData.inOrOutBlock,QIODevice::WriteOnly);

    /*获得文件名称*/
    QString currentFilename = transferData.fileName.right(transferData.fileName.size() \
                                                          - transferData.fileName.lastIndexOf('/')-1);
    qDebug()<<"发送的文件名: "<<currentFilename;

    /*保留总大小信息空间、命令、文件名大小信息空间、然后输入文件名*/
    sendOut << qint64(0) << qint64(0) << qint64(0)<< currentFilename;

    /*数据总的大小*/
    qDebug() << "totalBytes: " << transferData.totalBytes;
    qDebug() << "inOrOutBlock size: " << transferData.inOrOutBlock.size();

    transferData.totalBytes += transferData.inOrOutBlock.size();

    sendOut.device()->seek(0);

    /*填充实际的存储空间   传输文件指令*/
    sendOut << transferData.totalBytes<<_TRANSFER_FILE_\
            <<qint64((transferData.inOrOutBlock.size()-(sizeof(qint64)*3)));

    qDebug()<<"加上文件头文件的总大小:"<<transferData.totalBytes
           <<"发送的命令为: "<<_TRANSFER_FILE_\
          <<"文件头的大小: "<<transferData.inOrOutBlock.size()\
         <<"文件名字的大小: "<<qint64((transferData.inOrOutBlock.size()-(sizeof(qint64)*3)));

    auto sum = tcpsocket->write(transferData.inOrOutBlock);

    qDebug()<<"sum = "<<sum<<endl;

    transferData.bytesToWrite = transferData.totalBytes - sum;
    qDebug() << "文件内容大小：" << transferData.bytesToWrite;

    /*表示数据没有发送完*/
    if(transferData.bytesToWrite>0)
    {
        /*发送文件内容部分*/
        transferData.inOrOutBlock = transferData.localFile->readAll();
        tcpsocket->write(transferData.inOrOutBlock);
        transferData.inOrOutBlock.resize(0);
    }
    transferData.localFile->close();
}

//上传
void ClientWidget::on_up_pushButton_clicked()
{
    transferData.fileName = QFileDialog::getOpenFileName(this);
    if(!transferData.fileName.isEmpty())
    {
        qDebug()<<tr("打开文件成功")<<endl;
    }
    sendFile(transferData.fileName);
}

//下载
void ClientWidget::on_download_pushButton_clicked()
{

}
