#ifndef CALCU_H
#define CALCU_H
#include "cal.h" //���㵥Ԫ
#include "get2operands.h"//��ȡ������
#include "getnextchar.h"//��ȡ��һ���ַ�
#include "isoperator.h"//�ж��Ƿ�Ϊ������
#include "isp.h"//����վ�����ȼ�
#include "osp.h"//����վ�����ȼ�
#include "isdigit.h"
#include "QString" //�����ַ���
#include "QDebug"
#include <iostream>
#include "cmath"

class calcu
{
public:
    calcu();
    //��ʼ��

    //ջ��ʱδд��
    MyLStack<double> OPND; //������ջ����
    MyLStack<char> OPTR; //������ջ����
    QString formula; //���ʽ�ݴ�
    char prior_char;//��ǰ�����ַ���ǰһ���ַ�,��Ϊ������Ϊ0
    char ch;//��ǰ������ַ�
    double r;//��Ԫ�������ݴ�
    double x;//����ʱ������1
    double y;//����ʱ������2
    char f;//����ʱ������
    double t;//��������ʱ����
    QString message;//��Ϣ
    QString digittemp;//
    cal *mycal;//������㵥Ԫ
    getnextchar *mygetnextchar;
    get2operands *myget2operands;
    isoperator *myisoperator;
    isp *myisp;
    osp *myosp;
    Isdigit *myisdigit;

    double getReult();//���ش�
};

#endif // CALCU_H
