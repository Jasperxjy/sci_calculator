#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建输入框，按钮，计算单元，提示框，答案框的对象
    mycalculator=new calcu();
    inputEdit=new QLineEdit(this);
    beginbutton=new QPushButton(this);
    basicinfo=new QLabel(this);
    resultinfo=new QLabel(this);
    messagebox=new QLabel(this);

    //设置窗口大小
    this->resize(500,380);
    inputEdit->move(50,30);
    //设置提示信息
    inputEdit->setPlaceholderText("please input formula...");
    //让输入框显示“一键清除”按钮
    inputEdit->setClearButtonEnabled(true);
    //设置输入框大小
    inputEdit->resize(400,30);

    //设置按钮大小
    beginbutton->resize(70,30);
    //设置按钮文字
    beginbutton->setText("Start");
    //设置按钮位置
    beginbutton->move(215,100);

    //设置答案框位置
    resultinfo->move(100,150);
    //设置答案框大小
    resultinfo->resize(300,30);

    //设置提示框位置
    basicinfo->move(50,135);
    //设置提示框大小
    basicinfo->resize(400,300);
    //设置提示信息
    basicinfo->setText("Welcome to use Calculator Ver1.0 \n\n"
                       "Instructions for use\n expression contains: \n"
                       "1.plus(+),2.subtraction(-),3.multiplication(*),4.division(/)\n"
                       "5.modulo(%),6.square(^(fraction)),7.power(^)\n\n"
                       "Expression ends with '=' \n"
                       "After typing, press Enter or Start to get the answer");

    //设置消息框位置
    messagebox->move(50,65);
    //设置消息框大小
    messagebox->resize(300,30);

    //实现按确定得到答案
    QObject::connect(beginbutton,&QPushButton::clicked,[=](){
        QString temp = inputEdit->text();
        mycalculator->formula=temp;
        result=mycalculator->getReult();
        resultinfo->setText("Result: "+QString::number(result,'f',8));
        if(mycalculator->message!=""){
            messagebox->setText("Status:"+mycalculator->message);
        }
    });
    //实现回车得到答案
    QObject::connect(inputEdit,&QLineEdit::returnPressed,[=](){
        QString temp = inputEdit->text();
        mycalculator->formula=temp;
        result=mycalculator->getReult();
        resultinfo->setText("Result: "+QString::number(result,'f',8));
        if(mycalculator->message!=""){
            messagebox->setText("Status:"+mycalculator->message);
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;

}
