#include "isp.h"

isp::isp()
{

}

int isp::get(char ch)
{
    //Judge the incoming characters and return the priority in the stack
        switch (ch) {
        case '=':
            return 0;
            break;
        case '+':
            return 3;
            break;
        case '-':
            return 3;
            break;
        case '*':
            return 5;
            break;
        case '/':
            return 5;
            break;
        case '%':
            return 5;
            break;
        case '(':
            return 1;
            break;
        case ')':
            return 8;
            break;
        case '^':
            return 7;
            break;
        case '&':
            return 7;
            break;
        default:
            break;
        }
        return 1;//Õ¼Î»·û

}
