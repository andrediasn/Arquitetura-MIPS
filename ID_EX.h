#ifndef ID_EX_H_INCLUDED
#define ID_EX_H_INCLUDED
#include <iostream>
#include <fstream>
#include "EX_MEM.h"
#include "BancoRegistradores.h"
#include "Controle.h"
#include "OpLogicos.h"
#include "ALUcontrol.h"
#include "ALU.h"

using namespace std;


class ID_EX{
    private:
        Controle control;
        int PC;
        int desvioJump[32];
        int extend_15_0[32]; // Apos extensao de sinal
        int instruction_15_11[5]; 
        int instruction_20_16[5];
        int shamt[5];
        int readData1[32];
        int readData2[32];
        bool RegDst[2];
        bool ALUSrc;
        bool MemToReg[2];
        bool RegWrite;
        bool MemRead;
        bool MemWrite;
        bool Branch;
        bool ALUOp0;
        bool ALUOp1;
        bool Jump[2];
        int funct[6];
        void printSinais();

        
    
    public:
        ID_EX(int PC, int instruction_11_15[], int instruction_16_20[], int shamt[], Controle control, BancoRegistradores reg, OpLogicos op);
        ~ID_EX();
        EX_MEM* start();
        
};

#endif //ID_EX_H_INCLUDED