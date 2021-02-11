#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
namespace Ui {
  class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = nullptr);
  ~Dialog();
signals:
  void sendData(QString);//发送数据的信号
private slots:
  void on_pushButton_clicked();
  void getData(QString);//得到数据的槽函数
private:
  Ui::Dialog *ui;
};

#endif // DIALOG_H

