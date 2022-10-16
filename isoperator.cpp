#include "isoperator.h"

isoperator::isoperator()
{

}

bool isoperator::judge(char ch)
{
    switch (ch) {
    case '+' :
    return true;
        break;
    case '-' :
    return true;
        break;
    case '*' :
    return true;
        break;
    case '/' :
    return true;
        break;
    case '%' :
    return true;
        break;
    case '&' :
    return true;
        break;
    case '^' :
    return true;
        break;
    case '(' :
    return true;
        break;
    case ')' :
    return true;
        break;
    default:
        return false;
        break;      
    }
}
