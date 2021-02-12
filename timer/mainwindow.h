#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include<QDateTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;

private:
    Ui::MainWindow *ui;

private slots:
    void timerSlot();
    void timerSlot1();
    void timerSlot2();


};

#endif // MAINWINDOW_H
