#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>
#include <QMessageBox>
#include <QMessageLogger>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWidget; }
QT_END_NAMESPACE

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

    void sendFile(QString path);   //文件头信息发送函数


private slots:
    void on_ip_lineEdit_editingFinished();

    void on_port_lineEdit_editingFinished();

    void on_connectpushButton_clicked();

    void on_up_pushButton_clicked();

    void on_download_pushButton_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket *tcpsocket;

    QString ip_;
    QString port_;

    QFile *file;

    struct rcvOrSendDataPack{
        /*共用部分*/
        QFile *localFile;           //存放本地文件
        qint64 totalBytes;          //存放总大小信息
        QString fileName;           //存放文件名
        QByteArray inOrOutBlock;    //数据缓冲区
        /*发送相关*/
        qint64 bytesWritten;        //已经发送数据大小
        qint64 bytesToWrite;        //剩余数据的大小
        qint64 payloadSize;         //每次发送数据的大小
        int command;                //发送命令
        /*接收相关*/
        qint64 bytesReceived;       //已收到数据的大小
        qint64 fileNameSize;        //文件名的大小信息
    };
    struct rcvOrSendDataPack transferData;

    struct DirInformation{
        char fileName[256];           //文件名字
        char dirName[256];            //目录名字
        unsigned int isDirectory;     //是否是目录
        unsigned int isFile;          //是否是文件
        unsigned int topDir;          //是否是顶层目录
    };

    struct DirInformation dirInfo;

};
#endif // CLIENTWIDGET_H
