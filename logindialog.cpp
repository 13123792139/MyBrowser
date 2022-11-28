#include "logindialog.h"
#include "ui_logindialog.h"

#define max_user 100
#define max_length 100

using namespace std;

char user_name[max_user][max_length];
char user_password[max_user][max_length];

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_buttonBox_accepted()
{
       FILE *fp = NULL;
       fp = fopen("config.dat", "a+");
       int num = 0;
       while (!feof(fp)) {
   //        读取文件中的用户名和密码，并分别存入数组
           fscanf(fp, "%s\n", &user_name[num]);
           fscanf(fp, "%s\n", &user_password[num]);
           num++;
       }
       fclose(fp);
       string input_name=ui->loginLineEdit->text().toStdString();
       string input_password=ui->password_lineEdit->text().toStdString();
       int pointer = 0;
       QMessageBox msgBox;   // 生成对象
       msgBox.setWindowTitle("提示");
       //是否找到用户名
       int isFind = 0;
       for (; pointer < num; ++pointer) {
           if (strcmp(input_name.c_str(), user_name[pointer]) == 0) {
               isFind = 1;
               break;
           }
       }
       if (isFind == 0) {
           msgBox.setText("无此用户名！");    // 设置文本
           msgBox.exec();
           return;
       }
       if (strcmp(input_password.c_str(), user_password[pointer]) == 0) {
           QAxWidget *flash = new QAxWidget(0, 0);      //QAxWidget使用的是ActiveX插件
           flash->resize(800, 400);                    //设置该控件的初始大小
           flash->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));//注册组件ID
           flash->setProperty("DisplayAlerts", false);//不显示警告信息
           flash->setProperty("DisplayScrollBars", false);//不显示滚动条
           QString webstr = QString("https://m.baidu.com/?pu=sz@1321_480");//设置要打开的网页
           flash->dynamicCall("Navigate(const QString&)", webstr);//显示网页
           flash->show();
           msgBox.setText("登录成功！");    // 设置文本
           msgBox.exec();
           return;
       } else {
           msgBox.setText("密码错误！");    // 设置文本
           msgBox.exec();
           return;
       }
}

