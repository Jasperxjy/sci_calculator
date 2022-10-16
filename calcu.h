#ifndef CALCU_H
#define CALCU_H
#include "cal.h" //计算单元
#include "get2operands.h"//获取操作数
#include "getnextchar.h"//获取下一个字符
#include "isoperator.h"//判断是否为操作符
#include "isp.h"//返回站内优先级
#include "osp.h"//返回站外优先级
#include "isdigit.h"
#include "QString" //引入字符串
#include "QDebug"
#include <iostream>
#include "cmath"

class calcu
{
public:
    calcu();
    //初始化

    //栈暂时未写出
    MyLStack<double> OPND; //操作数栈定义
    MyLStack<char> OPTR; //操作符栈定义
    QString formula; //表达式暂存
    char prior_char;//当前处理字符的前一个字符,若为数，则为0
    char ch;//当前处理的字符
    double r;//单元计算结果暂存
    double x;//运算时操作数1
    double y;//运算时操作数2
    char f;//运算时操作符
    double t;//操作数临时变量
    QString message;//消息
    QString digittemp;//
    cal *mycal;//引入计算单元
    getnextchar *mygetnextchar;
    get2operands *myget2operands;
    isoperator *myisoperator;
    isp *myisp;
    osp *myosp;
    Isdigit *myisdigit;

    double getReult();//返回答案
};

#endif // CALCU_H
