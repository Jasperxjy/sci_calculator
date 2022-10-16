#include "isdigit.h"

Isdigit::Isdigit()
{

}

bool Isdigit::judge(char ch)
{
    if(ch>='0'&&ch<='9'){
    return true;
    }else{
        return false;
    }
}
