#include <iostream>
#include "poligon.h"
#define PI 3.14159265
#include <fstream>
#include "patrat.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include "dreptunghi.h"
#include "stiva.h"
using namespace std;

int main()
{

   //char s1[100],s2[100];

  // cin>>s1;
  // cin>>s2;



  ifstream f("date.in");
   ofstream g("date.out");

   char s[1000];
   poligon*v[1000];
   int i=0;
   punct p;
   stiva stiva;
   int numar=0;
   while(f.getline(s,999))
   {
      if(strstr(s,"Vreau")&&strchr(s,'('))
        {
            if(strstr(s,"poligon"))
                    {v[i]=new poligon(strstr(s,"poligon"));
                     i++;
                    }
            if(strstr(s,"patrat"))
                    {

                    v[i]=new patrat(strstr(s,"patrat"));
                    i++;
                    }
                if(strstr(s,"dreptunghi"))
            {

            v[i]=new dreptunghi(strstr(s,"dreptunghi"));
            i++;

            }
        }

        if(strstr(s,"Muta")&&strstr(s,"figura"))
        {
                int id=0;
                int m=strlen(strstr(s,"figura"));
                    int n=strlen(s);
                    int j=(n-m-1);
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){id=id*10+s[j]-'0';j++;}
                if(v[id])v[id]->translatare(s);

        }
        if(strstr(s,"Roteste")&&strstr(s,"figura"))
        {
            int id=0;
            int m=strlen(strstr(s,"figura"));
                    int n=strlen(s);
                    int j=(n-m-1);
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){id=id*10+s[j]-'0';j++;}
                if(v[id])v[id]->rotire(s);

        }
        if(strstr(s,"Sterge"))
        {
            int id=0;
            int m=strlen(strstr(s,"figura"));
                    int n=strlen(s);
                    int j=(n-m-1);
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){id=id*10+s[j]-'0';j++;}
                delete v[id];
                v[id]=NULL;
        }













       if(strstr(s,"Daca"))
       {	//cout<<2;
           char*p=strstr(s,"figura");
            int k=0;
            while(!isdigit(p[0]))p++;
            while(isdigit(p[0])){k=k*10+p[0]-'0';p++;}
            int id=k;
            k=0;
            while(!isdigit(p[0]))p++;
            while(isdigit(p[0])){k=k*10+p[0]-'0';p++;}
            int id1=k;

            if(v[id]->intersect(*(v[id1]))) stiva.push(1);
                else stiva.push(-1);

       }
             while(!stiva.empty())
             {
                 f.getline(s,999);
                 if(strstr(s,"Vreau")&&stiva.top()>0)
                 {


                            if(strstr(s,"poligon"))
                            {v[i]=new poligon(strstr(s,"poligon"));
                            i++;}

                            else
                              if(strstr(s,"patrat"))
                               {
                                v[i]=new patrat(strstr(s,"patrat"));
                                i++;}
                                else
                                  {
                                   v[i]=new dreptunghi(strstr(s,"dreptunghi"));
                                   i++;}
                }


        if(strstr(s,"Muta")&&stiva.top()>0)
        {
                int id=0;
                int m=strlen(strstr(s,"figura"));
                    int n=strlen(s);
                    int j=(n-m-1);
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){id=id*10+s[j]-'0';j++;}
                if(v[id])v[id]->translatare(s);

        }
        if(strstr(s,"Roteste")&&stiva.top()>0)
        {
            int id=0;
            int m=strlen(strstr(s,"figura"));
                    int n=strlen(s);
                    int j=(n-m-1);
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){id=id*10+s[j]-'0';j++;}
                if(v[id])v[id]->rotire(s);

        }
        if(strstr(s,"Sterge")&&stiva.top()>0)
        {
            int id=0;
            int m=strlen(strstr(s,"figura"));
                    int n=strlen(s);
                    int j=(n-m-1);
                while(!isdigit(s[j]))j++;
                while(isdigit(s[j])){id=id*10+s[j]-'0';j++;}
                delete v[id];
                v[id]=NULL;
        }

        if(strstr(s,"Daca"))
           {
               if(stiva.top()>0)
               {
                   char*p=strstr(s,"figura");
                   int k=0;
                   while(!isdigit(p[0]))p++;
                   while(isdigit(p[0])){k=k*10+p[0]-'0';p++;}
                   int id=k;
                   k=0;
                   while(!isdigit(p[0]))p++;
                   while(isdigit(p[0])){k=k*10+p[0]-'0';p++;}
                   int id1=k;

                   if(v[id]->intersect(*(v[id1]))) stiva.push(1);
                    else stiva.push(-1);
               }
                else numar++;

           }

        if(strstr(s,"Altfel")&&numar==0)
        {
            int a=stiva.top()*(-1);
            stiva.pop();
            stiva.push(a);}



        if(strstr(s,"Gata")==s)
        {  if(numar) numar--;
            else stiva.pop();
        }
             }

        }




int n=i;
//cout<<n;
for(i=0;i<n;i++)
{   if(v[i]!=NULL)
    {
    g<<i;
    v[i]->afisare(g);
    }
}
g.close();
f.close();

    return 0;
}
