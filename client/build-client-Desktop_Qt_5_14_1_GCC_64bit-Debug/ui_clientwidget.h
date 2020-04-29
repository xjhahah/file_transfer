/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *ip_lineEdit;
    QPushButton *connectpushButton;
    QLabel *label_2;
    QLineEdit *port_lineEdit;
    QPushButton *dis_pushButton;
    QTextBrowser *textBrowser;
    QPushButton *up_pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *download_pushButton;
    QProgressBar *progressBar;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(604, 499);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClientWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ip_lineEdit = new QLineEdit(ClientWidget);
        ip_lineEdit->setObjectName(QString::fromUtf8("ip_lineEdit"));

        gridLayout->addWidget(ip_lineEdit, 0, 1, 1, 1);

        connectpushButton = new QPushButton(ClientWidget);
        connectpushButton->setObjectName(QString::fromUtf8("connectpushButton"));

        gridLayout->addWidget(connectpushButton, 0, 2, 1, 1);

        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        port_lineEdit = new QLineEdit(ClientWidget);
        port_lineEdit->setObjectName(QString::fromUtf8("port_lineEdit"));

        gridLayout->addWidget(port_lineEdit, 1, 1, 1, 1);

        dis_pushButton = new QPushButton(ClientWidget);
        dis_pushButton->setObjectName(QString::fromUtf8("dis_pushButton"));

        gridLayout->addWidget(dis_pushButton, 1, 2, 1, 1);

        textBrowser = new QTextBrowser(ClientWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 2, 0, 4, 2);

        up_pushButton = new QPushButton(ClientWidget);
        up_pushButton->setObjectName(QString::fromUtf8("up_pushButton"));

        gridLayout->addWidget(up_pushButton, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 308, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        download_pushButton = new QPushButton(ClientWidget);
        download_pushButton->setObjectName(QString::fromUtf8("download_pushButton"));

        gridLayout->addWidget(download_pushButton, 4, 2, 1, 1);

        progressBar = new QProgressBar(ClientWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 6, 0, 1, 2);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "ClientWidget", nullptr));
        label->setText(QCoreApplication::translate("ClientWidget", "IP\357\274\232", nullptr));
        connectpushButton->setText(QCoreApplication::translate("ClientWidget", "connect", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWidget", "Port\357\274\232", nullptr));
        dis_pushButton->setText(QCoreApplication::translate("ClientWidget", "disconnect", nullptr));
        up_pushButton->setText(QCoreApplication::translate("ClientWidget", "up", nullptr));
        download_pushButton->setText(QCoreApplication::translate("ClientWidget", "download", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
