#include "poligon.h"
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define PI 3.14159265
int determinant(punct a,punct b,punct c)
{
    return a.getx()*b.gety()+b.getx()*c.gety()+a.gety()*c.getx()-b.gety()*c.getx()-c.gety()*a.getx()-b.getx()*a.gety();
}

poligon::poligon()
{
}

poligon::poligon(char*s)
{
    int m=strlen(s);
    int j=0,k=0,semn=1;
    for(int i=0;i<m;i++)
    {
        if(s[i]=='(')
        {   while(s[i]!=',')
                {   if(s[i]=='-')semn=-1;
                    if(isdigit(s[i]))k=k*10+s[i]-'0';
                    i++;
                }
            v[j].setx(k*semn);

            k=0;semn=1;
             while(s[i]!=')')
             {
                 if(s[i]=='-')semn=-1;
                 if(isdigit(s[i]))k=k*10+s[i]-'0';
                 i++;
             }
             v[j].sety(k*semn);
             j++;k=0;semn=1;
        }
    }
       nr=j; //nr de puncte
}


void poligon::translatare(char*s)
{

    int m=strlen(strstr(s,"cu"));
                    int n=strlen(s);
                    int j=(n-m-1);
                    int l=0;
                    int semn=1;
        while(!(isdigit(s[j]))&&s[j]!='-')j++;
        if(s[j]=='-'){semn=-1;
        j++;}

        while(isdigit(s[j])){l=l*10+s[j]-'0';j++;}
        l*=semn;

     if(strstr(s,"in sus"))
            for(int i=0;i<nr;i++)
                v[i].sety(v[i].gety()+l);

    if(strstr(s,"in jos"))
            for(int i=0;i<nr;i++)
                v[i].sety(v[i].gety()-l);

   if(strstr(s,"in stanga"))
            for(int i=0;i<nr;i++)
                v[i].setx(v[i].getx()-l);

    if(strstr(s,"in dreapta"))
            for(int i=0;i<nr;i++)
                v[i].setx(v[i].getx()+l);

}

void poligon::rotire(char*s)
{
    int u=0;
    punct p;
    int m=strlen(strstr(s,"cu"));
                    int n=strlen(s);
                    int j=(n-m-1);
                    int l=0;
                    int semn=1;
                    int k=0;
        while(!isdigit(s[j])&&s[j]!='-')j++;
        if(s[j]=='-'){semn=-1;
        j++;}
        while(isdigit(s[j])){u=u*10+s[j]-'0';j++;}
        u*=semn;
        semn=1;
        while(!isdigit(s[j])&&s[j]!='-')j++;
        if(s[j]=='-'){semn=-1;
        j++;}
         while(isdigit(s[j])){k=k*10+s[j]-'0';j++;}
        k*=semn;
        p.setx(k);
        k=0;
        semn=1;
        p.sety(k);
        while(!isdigit(s[j])&&s[j]!='-')j++;
        if(s[j]=='-'){semn=-1;
        j++;}
         while(isdigit(s[j])){k=k*10+s[j]-'0';j++;}
         p.sety(k);
     int x0=p.getx();
     int y0=p.gety();
     int i;
     int  si=sin(u*PI/180.0);
     int  c=cos(u*PI/180.0);
     int x,y;
     for(i=0;i<nr;i++)
               {
                 x=v[i].getx();
                 y=v[i].gety();
                 v[i].setx(x0+(x-x0)*c-(y-y0)*si);
                 v[i].sety(y0+(x-x0)*si+(y-y0)*c);
               }


}

void poligon::afisare(ofstream&f)
{
    sortare();
    f<<" poligon"<<endl;
    for(int i=0;i<nr;i++)
    f<<v[i].getx()<<' '<<v[i].gety()<<'\n';

}


int compare(const void *c,const void *d)
{   punct*a=(punct*)c;
    punct*b=(punct*)d;

    if(a->getx()>b->getx()) return 1;
    else if(a->getx()!=b->getx())return 0;
    if(a->gety()>b->gety()) return 1;
    else return 0;

}
void poligon::sortare()
{
    int i,k,j;
    punct aux;
for(i=1;i<=nr;i++)
for(j=nr-1;j>=i;j--)
if(v[j].getx()<v[j-1].getx() || v[j].getx()==v[j-1].getx() && v[j].gety()<v[j-1].gety()) {aux=v[j];v[j]=v[j-1];v[j-1]=aux;}
    }
/*
void poligon::sortare()
{
    qsort(v,nr,sizeof(punct),compare);
}
*/
void poligon::construieste()
{
    sortare();
    punct v1[42],v2[42];
    int i,j=2;
    sortare();
    v1[0]=v[0];
    v1[1]=v[1];
    for(i=2;i<nr;i++)
    {
        v1[j]=v[i];
        if(determinant(v1[j-2],v1[j-1],v1[j])>0)j++;
            else {
            while(determinant(v1[j-2],v1[j-1],v1[j])<=0)
            {
                v1[j-1]=v1[j];
                j--;
            }
            j++;
                }
    }
    int n1=j;
    j=2;
    v2[0]=v[nr-1];
    v2[1]=v[nr-2];
     for(i=nr-3;i>=0;i--)
    {
        v2[j]=v[i];
        if(determinant(v2[j-2],v2[j-1],v2[j])>0)j++;
            else{
            while(determinant(v2[j-2],v2[j-1],v2[j])<=0)
            {
                v2[j-1]=v2[j];
                j--;
            }
            j++;
                 }
    }

    int n2=j;
    for(i=0;i<n1;i++)
        v[i]=v1[i];
    for(i=1;i<n2-1;i++)
        v[i+n1-1]=v2[i];
    }

bool poligon::intersect(poligon a)
{
    this->construieste();
    a.construieste();

    int i;
    double arie=0;

    for(i=1;i<nr-1;i++)
        arie+=fabs(determinant(v[0],v[i],v[i+1]))/2.0;
    int j,h=0,k=0;
    double arie2=0;
   for(i=0;i<a.nr;i++)
        {   arie2=0;
            for(j=0;j<nr-1;j++)
                arie2+=fabs(determinant(a.v[i],v[j],v[j+1]))/2.0;
            arie2+=fabs(determinant(a.v[i],v[0],v[nr-1]))/2.0;
         //   cout<<arie2<<endl;
        if(arie2==arie)h++;
        if(h&&(arie2!=arie))k++;
        }






        //    cout<<"determinant pentru: "<<a.v[i].getx()<<" "<<a.v[i].gety()<<" | "<<v[j].getx()<<" "<<v[j].gety()<<" | "<<v[j+1].getx()<<" "<<v[j+1].gety()<<endl<<fabs(determinant(a.v[i],v[j],v[j+1]))/2.0<<endl;


    if(h==a.nr)return true;
    if(k)return true;
    arie2=0;
    arie=0;

    for(i=1;i<a.nr-1;i++)
    arie+=fabs(determinant(a.v[0],a.v[i],a.v[i+1]))/2.0;


    for(i=0;i<a.nr-1;i++)
        arie2+=abs(determinant(v[0],a.v[i],a.v[i+1]))/2.0;
        arie2+=abs(determinant(v[0],a.v[0],a.v[nr-1]))/2.0;
        if(arie2==arie)return true;
    return false;





}
