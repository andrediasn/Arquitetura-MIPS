#ifndef OPLOGICOS_H_INCLUDED
#define OPLOGICOS_H_INCLUDED
#include <iostream>

class OpLogicos{
    private:
        int vetExtSinal [32];

    public:
        OpLogicos(){}
        ~OpLogicos(){}

        void extensorSinal(int vetIn[]){
            if(vetIn[0]==0){
                for(int i=0;i<16;i++)
                    this->vetExtSinal[i] = 0;
                for(int i=16;i<32;i++)  
                    this->vetExtSinal[i] = vetIn[i-16];
            }
            else{
                for(int i=0;i<16;i++)
                    this->vetExtSinal[i] = 1;
                for(int i=16;i<32;i++)  
                    this->vetExtSinal[i] = vetIn[i-16];
            }
        }

        int* getExtensorSinal(){
            return this->vetExtSinal;
        }


        int* deslocamentoEsquerda(int vet[]);
        int* mutiplexador(int vet1[], int vet2[], bool control);
        int andLogico(int PC, bool zeroAlu, bool algumaCoisaDaM); // returna PCsec
};


#endif // OPLOGICOS_H_INCLUDED