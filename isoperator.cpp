#include "isoperator.h"

isoperator::isoperator()
{

}

bool isoperator::judge(char ch)
{
    switch (ch) {
    case '+' :
    return true;
    case '-' :
    return true;
    case '*' :
    return true;
    case '/' :
    return true;
    case '%' :
    return true;
    case '&' :
    return true;
    case '^' :
    return true;
    default:
        return false;
    }
}
