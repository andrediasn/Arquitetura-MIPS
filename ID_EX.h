#ifndef ID_EX_H_INCLUDED
#define ID_EX_H_INCLUDED
#include <iostream>
#include "BancoRegistradores.h"
#include "Controle.h"
#include "OpLogicos.h"
class ID_EX{
    private:
        int PC;
        int instruction_15_0[32]; // Apos extensao de sinal
        int instruction_15_11[5]; 
        int instruction_20_16[5];
        int readData1[32];
        int readData2[32];
        bool RegDst;
        bool ALUSrc;
        bool MemtoReg;
        bool RegWrite;
        bool MemRead;
        bool MemWrite;
        bool Branch;
        bool ALUOp0;
        bool ALUOp1;


        void setReadData();
        void setControl();
        void setExtSinal();
    
    
    public:
        ID_EX(int PC, int instruction_11_15[], int instruction_16_20[]);
        ~ID_EX();
        void start();

        ID_EX* get();
             
    

    
};

#endif //ID_EX_H_INCLUDED