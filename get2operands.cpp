#include "get2operands.h"

get2operands::get2operands()
{

}

bool get2operands::get(MyLStack<double> &opend, double &x, double &y)
{

    if(opend.length()>=2){
        //若为正常情况，站外低于站内时 一定有大于两个操作数
        x=opend.pop();
        y=opend.pop();

    }else{
        //若操作数小于两个，说明出现了符号过多的错误

        return false;
    }

    //请编写
    return true;//占位符
}

