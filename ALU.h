#ifndef ALU_H_INCLUDED                                       
#define ALU_H_INCLUDED
#include <math.h>
class ALU 
{
    private:
    int operation[4];  // entrada, vem do  ALUcontrol
    int aluResult[32];     // saida       
    bool zero = false;     // saida 
    int readData1[32];  // valor do registrador 1
    int readData2[32];  // valor do registrador 2

    int* soma(int vet1[], int vet2[], int result[]){
        int aux = 0;
            for(int i = 31; i >= 0; i--){
                //std::cout << vet1[i] << " + " << vet2[i] << " + " << aux << " = " << vet1[i] + vet2[i] + aux;
                if(vet1[i] + vet2[i] + aux == 2){
                    aux = 1;
                    result[i] = 0;
                }else if(vet1[i] + vet2[i] + aux == 3){
                    aux = 1;
                    result[i] = 1;
                }else{
                    result[i] = vet1[i] + vet2[i] + aux;
                    aux = 0;
                }
                //std::cout << " = " << result[i] << std::endl;
            }
        return result;
    }
    
    int* inverte(int vet[], int result[]){
        for(int i = 0; i < 32; i++){
            if(vet[i] == 1)
                result[i] = 0;
            else
                result[i] = 1;
        }
        return result;
    }

    public:
    ALU() { std::cout << " -> ALU" << std::endl;}
    
    ~ALU() {}

    
    void setAluResult(int op[4],int reg1[32], int reg2[32]){
        for(int i = 0; i < 4; i++)
            operation[i] = op[i];
        for(int i = 0; i < 32; i++){
            readData1[i] = reg1[i];
            readData2[i] = reg2[i];
        } 
        if(operation[1] == 0 && operation[2] == 1 && operation[3] == 0) {            // operação de add
            int *aux = new int [32];
            aux = soma(readData1, readData2, aux);
            for(int i = 0; i < 32 ; i++){
                aluResult[i] = aux[i];
            }
        }else if(operation[1] == 1 && operation[2] == 1 && operation[3] == 0){      // operação de sub 
            int *aux = new int [32];
            aux = inverte(readData2, aux);
            int ultimo1[32];
            for(int i = 0; i < 31; i++)
                ultimo1[i] = 0;
            ultimo1[31] = 1;
            aux = soma(aux, ultimo1, aux);
            aux = soma(readData1, aux, aux);
            for(int i = 0; i < 32; i++)
                aluResult[i] = aux[i];
        }else if(operation[1] == 0 && operation[2] == 0 && operation[3] == 0){      // operaçao AND
            for(int i = 31; i >= 0; i--){
                if(readData1[i] == 1 && readData2[i] == 1)
                    aluResult[i] = 1;
                else
                    aluResult[i] = 0;
            }
        }else if(operation[1] == 0 && operation[2] == 0 && operation[3] == 1){       // operação OR
            for(int i = 31; i >= 0; i--){
                if(readData1[i] == 1 || readData2[i] == 1){
                    aluResult[i] = 1;
                }else{
                    aluResult[i] = 0;
                }
            }
        }else{                                                                      // operação set less than
            int id1 = 0, id2 = 0;
            for(int i = 0; i < 32; i++){ 
                id1 += readData1[i] * pow(2,31-i); 
                id2 += readData2[i] * pow(2,31-i);
            }
            if(id1 < id2){
               zero = true;
            }
        }
        
    }

    
    int* getAluResult() {return aluResult;}
    bool getZeroAlu()   {return zero;}

};


#endif // ALU_H_INCLUDED