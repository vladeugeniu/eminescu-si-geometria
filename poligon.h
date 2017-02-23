#ifndef POLIGON_H
#define POLIGON_H
#include "punct.h"
#include <fstream>
#include <cstdio>
using namespace std;
class poligon
{   protected:
    punct v[42];
    int nr;
private:

    //bool compare(punct&a,punct&b);
    public:
        poligon();
        poligon(char*);
        void translatare(char*);
        void rotire(char*);
        virtual void afisare(ofstream&f);
        void sortare();
        //int determinant(punct,punct,punct);
        void construieste();
        punct* getv();
        void setnr(int);
        bool intersect(poligon a);
//int compare(punct&a,punct&b);
};

#endif // POLIGON_H
