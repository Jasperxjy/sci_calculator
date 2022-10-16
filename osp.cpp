#include "osp.h"

osp::osp()
{

}

int osp::get(char ch)
{
    //Judge the incoming characters and return the off stack priority
        switch (ch) {
        case '=':
            return 0;
            break;
        case '+':
            return 2;
            break;
        case '-':
            return 2;
            break;
        case '*':
            return 4;
            break;
        case '/':
            return 4;
            break;
        case '%':
            return 4;
            break;
        case '(':
            return 8;
            break;
        case ')':
            return 1;
            break;
        case '^':
            return 6;
            break;
        case '&':
            return 6;
            break;
        default:
            break;
        }
        return 1;//Õ¼Î»·û

}
