#ifndef DREPTUNGHI_H
#define DREPTUNGHI_H

#include "poligon.h"


class dreptunghi : public poligon
{
    public:
        dreptunghi(char*s);
        void afisare(ofstream&f);
};

#endif // DREPTUNGHI_H
