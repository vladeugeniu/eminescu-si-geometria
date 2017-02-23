#include "stiva.h"

stiva::stiva()
{
    i=0;

}
void stiva::pop()
{

 i--;
 //return v[i];
}
void stiva::push(int a){i++;v[i]=a;}
int stiva::top(){return v[i];}
bool stiva::empty(){if(i==0) return true; return false;}
