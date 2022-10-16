#include "calcu.h"
using namespace std;
calcu::calcu()
{
    //新建对象
    mycal=new cal();
    myget2operands=new get2operands();
    mygetnextchar=new getnextchar();
    myisdigit=new Isdigit();
    myisoperator = new isoperator();
    myisp=new isp();
    myosp=new osp();
    //初值设定
    message="normal";
    digittemp="";
    ch='=';//初始化当前处理字符
    OPTR.push(ch);//初始先压等号
    prior_char='=';// 初始化当前的前一个数字
}

double calcu::getReult()
{
    OPTR.push(ch);//初始先压等号
    prior_char='=';// 初始化当前的前一个数字
    mygetnextchar=new getnextchar(formula);//将本次计算的式子引入

    mygetnextchar->GetNextChar(ch);//将第一个字符传入ch
    //OPTR.topValue(OPTR_top) 未知作用
    while(!(OPTR.topValue()=='='&&ch=='=')){
        //当操作符栈顶元素与当前符号不同时为 = 开始循环   
        if(myisdigit->judge(ch)||ch=='.'){
            //当下一个字符是数或者是.时
            digittemp.append(ch);
            prior_char='0';
            mygetnextchar->GetNextChar(ch);

        }else if (!myisoperator->judge(ch)) {
            //当下一个字符不是操作符
            message="err:There are illegal characters,\n      please reenter formula";
            return -1;

        }else{
            //当下一个字符是操作符时
            //判断操作数暂存有无数字
             if(!digittemp.isEmpty()){
                 double num=digittemp.toDouble();//有数字时转换为数字
                 OPND.push(num);//压入操作数栈
                 digittemp="";//清空操作数缓存区
             }
            if(prior_char=='='||prior_char=='('&&(ch=='+'||ch=='-')){
                //当出现 = 或者 出现 （-a  以及（+a  时将 0 作为操作数压入
               t=0.0;
               OPND.push(t);
            }
            if (myosp->get(ch)>myisp->get(OPTR.topValue())){
                //若当前字符的站外优先级 高于 栈顶的站内优先级
                OPTR.push(ch);//压入当前操作符
                prior_char=ch;//更新前一个字符
                mygetnextchar->GetNextChar(ch);//处理下一个字符
            }else if(myosp->get(ch)<myisp->get(OPTR.topValue())){
                //若当前字符的站外优先级 低于 于栈顶的站内优先级
                    bool t;//存储get操作数的返回信息
                    t=myget2operands->get(OPND,y,x);
                    if(!t){
                        message="err:Your formula is illegal,\np      lease check and reenter formula";
                        return -2;
                    }
                    f=OPTR.pop();//弹出一个操作符
                int a;//存储计算部分的返回信息
                a=mycal->get(f,x,y,r);
                if(a==-1){
                    //当得到答案的部分返回-1，说明发生除零错误
                    message="err:There is a divide-by-zero error,\n      please reenter formula";
                    return -2;
                }else if (a==-2) {
                    //当得到答案的部分返回-2，说明发生开方错误
                    message="err:There is a squared error,\np      lease check and reenter formula";
                    return -2;
                }else if (a==-3) {
                    //当得到答案的部分返回-2，说明发生结构错误
                    message="err:Your formula is illegal,\np      lease check and reenter formula";
                    return -2;
                }else{
                    //未出现计算错误，将结果压入操作数栈
                    OPND.push(r);
                    //不读取下一个字符，表示继续处理当前字符，同时也不更新上一个字符
                }
            }else{
                //两者相等
                OPTR.pop();
                prior_char=ch;//更新前一个字符
                mygetnextchar->GetNextChar(ch);//处理下一个字符
            }
        }
    }
    message="normal";
    return OPND.topValue();  
}
