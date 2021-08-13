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

    void attAlu(int op[4],int reg1[32], int reg2[32]); // precisa do operation e dos dois registradores
    void setAluResult();
    bool getZero();
    int* getAluResult();

};


#endif // ALU_H_INCLUDED