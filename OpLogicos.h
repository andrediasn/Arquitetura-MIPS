#ifndef OPLOGICOS_H_INCLUDED
#define OPLOGICOS_H_INCLUDED

class OpLogicos{
    private:

    public:
    OpLogicos();
    ~OpLogicos();

    int* extensorSinal(int vetIn[]);
    int* deslocamentoEsquerda(int vet[]);
    int* mutiplexador(int vet[], int tipo[]);
    int andLogico(int PC, bool zeroAlu, bool algumaCoisaDaM); // returna PCsec
};


#endif // OPLOGICOS_H_INCLUDED