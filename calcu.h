#ifndef CALCU_H
#define CALCU_H
#include "cal.h" //计算单元
#include "get2operator.h"//获取操作数
#include "getnextchar.h"//获取下一个字符
#include "isdigit.h"//判断是否为数字
#include "isoperator.h"//判断是否为操作符
#include "isp.h"//返回站内优先级
#include "osp.h"//返回站外优先级

#include "mylstack.h" //引入栈
#include "QString" //引入字符串
#include "QDebug"

class calcu
{
public:
    calcu();
    //初始化
    //MyLStack<double> OPND; //操作数栈定义
    //MyLStack<char> OPTR; //操作符栈定义
    QString ch; //表达式暂存
    double getReult();
};

#endif // CALCU_H
