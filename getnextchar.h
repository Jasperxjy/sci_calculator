#ifndef GETNEXTCHAR_H
#define GETNEXTCHAR_H
#include "QString"

class getnextchar
{
public:
    getnextchar();
    getnextchar(QString formula);
    QString temp;
    void GetNextChar(char &ch);
};

#endif // GETNEXTCHAR_H
