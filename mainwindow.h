#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLineEdit" //引入输入框
#include "calcu.h" //引入计算器
#include "QPushButton"
#include "QLabel" //引入提示框

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    calcu *mycalculator;
    QLineEdit *inputEdit;
    QPushButton *beginbutton;
    QLabel *basicinfo;
    QLabel *resultinfo;
    QLabel *messagebox;
    double result;

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
