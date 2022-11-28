#include "baidu.h"
#include "ui_baidu.h"

Baidu::Baidu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Baidu)
{
    ui->setupUi(this);
    QAxWidget *flash = new QAxWidget(0, 0);      //QAxWidget使用的是ActiveX插件
    flash->resize(600, 400);                    //设置该控件的初始大小
    flash->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));//注册组件ID
    flash->setProperty("DisplayAlerts", false);//不显示警告信息
    flash->setProperty("DisplayScrollBars", true);//不显示滚动条
    QString webstr = QString("www.baidu.com");//设置要打开的网页
    flash->dynamicCall("Navigate(const QString&)", webstr);//显示网页
    flash->show();
}

Baidu::~Baidu()
{
    delete ui;
}
