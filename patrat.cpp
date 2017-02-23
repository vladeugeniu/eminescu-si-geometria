#include "patrat.h"
#include <iostream>
#include <cmath>
#include <cstring>
#define PI 3.14159265

patrat::patrat(char*s)
{
     int semn=1;
     punct p;
                    int m=strlen(strstr(s,"patrat"));
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

                int l=0;
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){l=l*10+s[j]-'0';j++;}
    int x=p.getx(),y=p.gety();
    v[0]=p;
    v[1].setx(x+l);
    v[1].sety(y);
    v[2].setx(x+l);
    v[2].sety(y+l);
    v[3].setx(x);
    v[3].sety(y+l);
    nr=4;
}

void patrat::afisare(ofstream&f)
{
    sortare();
    f<<" patrat"<<endl;
    for(int i=0;i<nr;i++){
    f<<v[i].getx()<<' '<<v[i].gety()<<'\n';
    }
}




/*
void patrat::rotire(int u,punct p)
{
        int l=fabs(v[0].getx()-v[1].getx());
        cout<<l<<endl;
        int s=sin(u*PI/180.0);
        int c=cos(u*PI/180.0);
        int x,y;
        int x0=p.getx();
        int y0=p.gety();
        x=v[0].getx();
        y=v[0].gety();
        v[0].setx(x0+(x-x0)*c-(y-y0)*s);
        v[0].sety(y0+(x-x0)*s+(y-y0)*c);

    v[1].setx(x+l);
    v[1].sety(y);
    v[2].setx(x+l);
    v[2].sety(y+l);
    v[3].setx(x);
    v[3].sety(y+l);



}
*/
