#include "punct.h"

punct::punct()
{
    x=0;
    y=0;
}
punct::punct(int a,int b){x=a,y=b;}
int punct::getx(){return x;}
int punct::gety(){return y;}
void punct::setx(int a){x=a;}
void punct::sety(int a){y=a;}
