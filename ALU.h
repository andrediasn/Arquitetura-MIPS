#ifndef ALU_H_INCLUDED                                       
#define ALU_H_INCLUDED
class ALU 
{
    private:
    int operation[4];  // entrada, vem do  ALUcontrol
    int aluResult[32];     // saida
    bool zero = 0;     // saida 
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
            // implementar
        }else if(operation[1] == 1 && operation[2] == 1 && operation[3] == 0){      // operação de sub 
            // implementar
        }else if(operation[1] == 0 && operation[2] == 0 && operation[3] == 0){      // operaçao AND
            // implementar
        }else if(operation[1] == 0 && operation[2] == 0 && operation[3] == 1){       // operação OR
            //implementar
        }else{                                                                      // operação set less than
            // implementar
        }
    }

    bool getZero() {return 0;}

    int* getAluResult() {return aluResult;}

};


#endif // ALU_H_INCLUDED