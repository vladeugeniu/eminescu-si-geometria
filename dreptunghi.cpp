#include "dreptunghi.h"
#include <iostream>
#include <cstring>
dreptunghi::dreptunghi(char*s)
{
     int semn=1;
     punct p;
                    int m=strlen(strstr(s,"dreptunghi"));
                    int n=strlen(s);
                    int j=(n-m-1);
                    int k=0;
                    while(s[j]!=',')
                {   if(s[j]=='-')semn=-1;
                    if(isdigit(s[j]))k=k*10+s[j]-'0';
                    j++;
                }
            p.setx(k*semn);
            k=0;semn=1;
             while(s[j]!=')')
             {
                 if(s[j]=='-')semn=-1;
                 if(isdigit(s[j]))k=k*10+s[j]-'0';
                 j++;
             }
             p.sety(k*semn);

             int lun=0;
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){lun=lun*10+s[j]-'0';j++;}
             int lat=0;
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){lat=lat*10+s[j]-'0';j++;}
    int x=p.getx(),y=p.gety();
    v[0]=p;
    v[1].setx(x+lun);
    v[1].sety(y);
    v[2].setx(x+lun);
    v[2].sety(y+lat);
    v[3].setx(x);
    v[3].sety(y+lat);
    nr=4;
}
void dreptunghi::afisare(ofstream&f)
{
    sortare();
     f<<" dreptunghi"<<endl;
    int i;
    for(i=0;i<nr;i++){
    f<<v[i].getx()<<' '<<v[i].gety()<<'\n';
    }
}
