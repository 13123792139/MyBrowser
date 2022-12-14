#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <string.h>
#include <QDialog>
#include <QMessageBox>
#include <QAxWidget>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
