#include "get2operands.h"

get2operands::get2operands()
{

}

bool get2operands::get(MyLStack<double> &opend, double &x, double &y)
{

    if(opend.length()>=2){
        //��Ϊ���������վ�����վ��ʱ һ���д�������������
        x=opend.pop();
        y=opend.pop();

    }else{
        //��������С��������˵�������˷��Ź���Ĵ���

        return false;
    }

    //���д
    return true;//ռλ��
}

