#ifndef ALUCONTROL_H_INCLUDED                                       
#define ALUCONTROL_H_INCLUDED
class ALUcontrol
{
    private:
        int Operation[4];       // é a saida da ALU
        int functField[6];      // Recebe da IF_ID
        bool ALUOp1;            // Recebe da IF_ID
        bool ALUOp0;            // Recebe da IF_ID
        

    public:
        ALUcontrol();
        ~ALUcontrol();

        void attALU(int vet[],bool Op1,bool Op2);    
        int* getOperation(); 
};
#endif // ALUCONTROL_H_INCLUDED