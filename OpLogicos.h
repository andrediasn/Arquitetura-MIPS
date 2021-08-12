#ifndef OPLOGICOS_H_INCLUDED
#define OPLOGICOS_H_INCLUDED
#include <iostream>

class OpLogicos{
    private:
        int vetExtSinal [32];

    public:
        OpLogicos();
        ~OpLogicos();

        void extensorSinal(int vetIn[]);
        int* getExtensorSinal();
        int* deslocamentoEsquerda(int vet[]);
        int* mutiplexador(int vet[], int tipo[]);
        int andLogico(int PC, bool zeroAlu, bool algumaCoisaDaM); // returna PCsec
};


#endif // OPLOGICOS_H_INCLUDED