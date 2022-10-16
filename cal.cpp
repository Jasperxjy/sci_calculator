#include "cal.h"

cal::cal()
{

}

int cal::get(char op,double x,double y,double &r)
{
    //���д
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
        if ( x < 0 && fmod(pow(y,-1),2) ==0 ){//������ż���η�
            return -2;
        }
        if ( x == 0 && y <= 0 ){//0�ķǸ����η�
            return -2;
        }
        r = pow(x,y);
    }
    if ( op == '(' || op == ')'){
        return -3;
    }
    if (op=='%'){
        if( y != 0 ){
            r = fmod(x,y);
        }else {
            return -1;
        }
    }


 return 1;//��ǰд��ռλ�� 1��ʾ�ɹ� -1��ʾ��0��-2��ʾ�������ִ���-3��ʾ�ṹ����
}
