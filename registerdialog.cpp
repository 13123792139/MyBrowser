#include "registerdialog.h"
#include "ui_registerdialog.h"
#define max_user 100
#define max_length 100

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_buttonBox_accepted()
{
    string input_name=ui->loginLineEdit->text().toStdString();
    string input_password=ui->password_lineEdit->text().toStdString();

    FILE *fp = NULL;
    fp = fopen("config.dat", "a+");
    fprintf(fp,input_name.c_str());
    fprintf(fp, "\n");
    fprintf(fp,input_password.c_str());
    fprintf(fp, "\n");
    fclose(fp);
    QMessageBox msgBox;   // 生成对象
    msgBox.setWindowTitle("提示");
    msgBox.setText("注册成功！");    // 设置文本
    msgBox.exec();
}

