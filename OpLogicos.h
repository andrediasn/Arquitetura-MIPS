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

        int* deslocamentoEsquerda(int vet[]){
            //int aux[tam-8];
            //for(int i=0;i<pos; i++)
            //    aux[i] = vet[pos+i];
            
            //return aux;

        }


        int ADD(int PC, int jump[]){
            // converter jump pra inteiro
            // desocobrir quantos bits tem
            int desvio; // = int jump
            return PC + desvio;
        }

        int* mutiplexador(int vet1[], int vet2[], bool control){
            if(control)
                return vet2;
            return vet1;
        }

        int andLogico(bool branch, bool zeroAlu){
            if(branch && zeroAlu)
                return true;
            return false;
        }
};


#endif // OPLOGICOS_H_INCLUDED