#include "cal.h"

cal::cal()
{

}

int cal::get(char op,double x,double y,double &r)
{
    //请编写
    if ( op == '+' ){
        r = x + y;
    }
    if ( op == '-' ){
        r = x - y;
    }
    if ( op == '*' ){
        r = x * y;
    }
    if ( op == '/' ){
        if( y != 0 ){
            r = x / y;
        }else {
            return -1;
        }
    }
    if ( op == '^' ){
        if ( x < 0 && fmod(y,2) ==0 ){//负数的偶数次方
            return -2;
        }
        if ( x == 0 && y <= 0 ){//0的非负数次方
            return -2;
        }
        r = pow(x,y);
    }
    if ( op == '(' || op == ')'){
        return -3;
    }

 return 1;//当前写的占位符 1表示成功 -1表示除0，-2表示开方出现错误，-3表示结构错误
}
