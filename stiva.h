#ifndef STIVA_H
#define STIVA_H


class stiva
{
    int v[1000];
    int i;
    public:
        stiva();
        void push(int);
        int top();
        void pop();
        bool empty();
};

#endif // STIVA_H
