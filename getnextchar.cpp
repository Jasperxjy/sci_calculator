#include "getnextchar.h"

getnextchar::getnextchar()
{

}

getnextchar::getnextchar(QString formula)
{
    temp=formula;
}

void getnextchar::GetNextChar(char &ch)
{
    ch=temp.at(0).unicode();
    temp.remove(0,1);
    //���д,ʽ�Ӵ洢��temp��
}
