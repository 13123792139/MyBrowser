#ifndef BAIDU_H
#define BAIDU_H

#include <QWidget>
#include <QAxWidget>
namespace Ui {
class Baidu;
}

class Baidu : public QWidget
{
    Q_OBJECT

public:
    explicit Baidu(QWidget *parent = nullptr);
    ~Baidu();

private:
    Ui::Baidu *ui;
};

#endif // BAIDU_H
