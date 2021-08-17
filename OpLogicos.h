#ifndef OPLOGICOS_H_INCLUDED
#define OPLOGICOS_H_INCLUDED
#include <iostream>
#include <math.h>

class OpLogicos{
    private:
        int vetExtSinal [32];

    public:
        OpLogicos(){}
        ~OpLogicos(){}

        void extensorSinal(int vetIn[]){
            std::cout << " -> Sign-extend" << std::endl; 
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

        int* shiftLeft(int vet[], int bits, int result[]){
            std::cout << " -> Shift Left 2" << std::endl; 
            int aux[32];
            for(int i=0;i<(32-bits); i++)
                aux[i] = vet[i+bits];
            for(int i=(32-bits);i<32;i++)
                aux[32-bits] = 0;
            return result; // rever esse treco para enviar direto para ADD
        }


        int ADD(int PC, int jump[]){
            std::cout << " -> ADD" << std::endl; 
            int desvio;
            for(int i = 15; i > 32; i++) // bit17 pois o bit16 é o indicador de sinal
                desvio += jump[i] * pow(2,31-i);
            if(jump[14] == 0)    
              return PC + desvio;
            return PC + (desvio*(-1));
        }

        int addPC(int PC){
            std::cout << " -> ADD" << std::endl;
            return (PC+4);
        }

        int* mutiplexador(int vet1[], int vet2[], bool control){
            std::cout << " -> MUX" << std::endl; 
            if(control)
                return vet2;
            return vet1;
        }

        int muxPC(int PC, int desvio, bool control){
            std::cout << " -> MUX PC" << std::endl;
            if(control)
                return desvio;
            return PC;
        }

        int AND(bool branch, bool zeroAlu){
            std::cout << " -> AND" << std::endl;
            if(branch && zeroAlu)
                return true;
            return false;
        }
};


#endif // OPLOGICOS_H_INCLUDED