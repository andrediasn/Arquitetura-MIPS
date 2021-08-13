#ifndef ALU_H_INCLUDED                                       
#define ALU_H_INCLUDED
class ALU
{
    private:
        int Operation[4];       // é a saida da ALU
        int functField[6];      // Recebe da IF_ID
        bool ALUOp1;            // Recebe da IF_ID
        bool ALUOp0;            // Recebe da IF_ID
        

    public:
        ALU();
        ~ALU();

        void attALU(int vet[],bool Op1,bool Op2);    
        int* getOperation(); 
};
#endif // ALU_H_INCLUDED