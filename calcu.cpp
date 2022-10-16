#include "calcu.h"
using namespace std;
calcu::calcu()
{
    //�½�����
    mycal=new cal();
    myget2operands=new get2operands();
    mygetnextchar=new getnextchar();
    myisdigit=new Isdigit();
    myisoperator = new isoperator();
    myisp=new isp();
    myosp=new osp();
    //��ֵ�趨
    message="normal";
    digittemp="";
    ch='=';//��ʼ����ǰ�����ַ�
    OPTR.push(ch);//��ʼ��ѹ�Ⱥ�
    prior_char='=';// ��ʼ����ǰ��ǰһ������
}

double calcu::getReult()
{
    OPTR.push(ch);//��ʼ��ѹ�Ⱥ�
    prior_char='=';// ��ʼ����ǰ��ǰһ������
    mygetnextchar=new getnextchar(formula);//�����μ����ʽ������

    mygetnextchar->GetNextChar(ch);//����һ���ַ�����ch
    //OPTR.topValue(OPTR_top) δ֪����
    while(!(OPTR.topValue()=='='&&ch=='=')){
        //��������ջ��Ԫ���뵱ǰ���Ų�ͬʱΪ = ��ʼѭ��   
        if(myisdigit->judge(ch)||ch=='.'){
            //����һ���ַ�����������.ʱ
            digittemp.append(ch);
            prior_char='0';
            mygetnextchar->GetNextChar(ch);

        }else if (!myisoperator->judge(ch)) {
            //����һ���ַ����ǲ�����
            message="err:There are illegal characters,\n      please reenter formula";
            return -1;

        }else{
            //����һ���ַ��ǲ�����ʱ
            //�жϲ������ݴ���������
             if(!digittemp.isEmpty()){
                 double num=digittemp.toDouble();//������ʱת��Ϊ����
                 OPND.push(num);//ѹ�������ջ
                 digittemp="";//��ղ�����������
             }
            if(prior_char=='='||prior_char=='('&&(ch=='+'||ch=='-')){
                //������ = ���� ���� ��-a  �Լ���+a  ʱ�� 0 ��Ϊ������ѹ��
               t=0.0;
               OPND.push(t);
            }
            if (myosp->get(ch)>myisp->get(OPTR.topValue())){
                //����ǰ�ַ���վ�����ȼ� ���� ջ����վ�����ȼ�
                OPTR.push(ch);//ѹ�뵱ǰ������
                prior_char=ch;//����ǰһ���ַ�
                mygetnextchar->GetNextChar(ch);//������һ���ַ�
            }else if(myosp->get(ch)<myisp->get(OPTR.topValue())){
                //����ǰ�ַ���վ�����ȼ� ���� ��ջ����վ�����ȼ�
                    bool t;//�洢get�������ķ�����Ϣ
                    t=myget2operands->get(OPND,y,x);
                    if(!t){
                        message="err:Your formula is illegal,\np      lease check and reenter formula";
                        return -2;
                    }
                    f=OPTR.pop();//����һ��������
                int a;//�洢���㲿�ֵķ�����Ϣ
                a=mycal->get(f,x,y,r);
                if(a==-1){
                    //���õ��𰸵Ĳ��ַ���-1��˵�������������
                    message="err:There is a divide-by-zero error,\n      please reenter formula";
                    return -2;
                }else if (a==-2) {
                    //���õ��𰸵Ĳ��ַ���-2��˵��������������
                    message="err:There is a squared error,\np      lease check and reenter formula";
                    return -2;
                }else if (a==-3) {
                    //���õ��𰸵Ĳ��ַ���-2��˵�������ṹ����
                    message="err:Your formula is illegal,\np      lease check and reenter formula";
                    return -2;
                }else{
                    //δ���ּ�����󣬽����ѹ�������ջ
                    OPND.push(r);
                    //����ȡ��һ���ַ�����ʾ��������ǰ�ַ���ͬʱҲ��������һ���ַ�
                }
            }else{
                //�������
                OPTR.pop();
                prior_char=ch;//����ǰһ���ַ�
                mygetnextchar->GetNextChar(ch);//������һ���ַ�
            }
        }
    }
    message="normal";
    return OPND.topValue();  
}
