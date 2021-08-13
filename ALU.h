#ifndef ALU_H_INCLUDED                                       
#define ALU_H_INCLUDED
#include <math.h>
class ALU 
{
    private:
    int operation[4];  // entrada, vem do  ALUcontrol
    int aluResult[32];     // saida
    int aluResultSlt = -1;       // saida para caso a operação seja Slt
    bool zero = false;     // saida 
    int readData1[32];  // valor do registrador 1
    int readData2[32];  // valor do registrador 2

    public:
    ALU();
    ~ALU();

    void attAlu(int op[4],int reg1[32], int reg2[32]){ // precisa do operation e dos dois registradores
        for(int i = 0; i < 4; i++)
            operation[i] = op[i];
        for(int i = 0; i < 32; i++){
            readData1[i] = reg1[i];
            readData2[i] = reg2[i];
        }    
    }

    void setAluResult(){
        if(operation[1] == 0 && operation[2] == 1 && operation[3] == 0) {            // operação de add
            int aux = 0;
            for(int i = 31; i >= 0; i--){
                if(readData1[i] + readData2[i] + aux == 2){
                    aux = 1;
                    aluResult[i] = 0;
                }else if(readData1[i] + readData2[i] + aux == 3){
                    aux = 1;
                    aluResult[i] = 1;
                }else{
                    aluResult[i] = readData1[i] + readData2[i];
                    aux = 0;
                }
            }
        }else if(operation[1] == 1 && operation[2] == 1 && operation[3] == 0){      // operação de sub 
            // implementar
        }else if(operation[1] == 0 && operation[2] == 0 && operation[3] == 0){      // operaçao AND
            for(int i = 31; i >= 0; i--){
                if(readData1[i] == 1 && readData2[i] == 1){
                    aluResult[i] = 1;
                }else{
                    aluResult[i] = 0;
                }
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
                id1 += readData1[i] * pow(2,4-i); 
                id2 += readData2[i] * pow(2,4-i);
            }
            if(id1 < id2){
               zero = true;
            }
        }
        
    }

    bool getZero() {return 0;}

    int* getAluResult() {return aluResult;}

};


#endif // ALU_H_INCLUDED