#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <string>
#include <QMessageBox>

using namespace std;

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
