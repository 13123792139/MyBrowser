#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    LoginDialog *ld=new LoginDialog(this);
    ld->show();
}


void MainWindow::on_registerButton_clicked()
{
    RegisterDialog *rd=new RegisterDialog(this);
    rd->show();
}


void MainWindow::on_pushButton_clicked()
{
    QAxWidget *flash = new QAxWidget(0, 0);      //QAxWidget使用的是ActiveX插件
    flash->resize(800, 400);                    //设置该控件的初始大小
    flash->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));//注册组件ID
    flash->setProperty("DisplayAlerts", false);//不显示警告信息
    flash->setProperty("DisplayScrollBars", false);//不显示滚动条
    QString webstr = QString("https://m.baidu.com/?pu=sz@1321_480");//设置要打开的网页
    flash->dynamicCall("Navigate(const QString&)", webstr);//显示网页
    flash->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    system ("shutdown -s -t 60");
    this->close();
    exit(0);
}

