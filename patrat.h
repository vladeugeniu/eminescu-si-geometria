#ifndef PATRAT_H
#define PATRAT_H

#include "poligon.h"

class patrat : public poligon
{
    public:
        patrat(char*);
       // void rotire(int,punct);
        void afisare(ofstream&f);
};


#endif // PATRAT_H
