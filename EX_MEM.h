#ifndef EX_MEM_H_INCLUDED
#define EX_MEM_H_INCLUDED
#include <iostream>
#include "MEM_WB.h"
#include "ALU.h"
#include "Controle.h"
#include "OpLogicos.h"
#include "DataMemory.h"



class EX_MEM{
    private:
        int PC;
        int Desvio;
        bool zeroAlu;
        int ALUresult[32];
        int readData2[32];
        int writeRegister[5]; 
        bool MemToReg;
        bool RegWrite;
        bool MemRead;
        bool MemWrite;
        bool Branch;
  
    public:
        EX_MEM(Controle control, int PC, int desvio, ALU operacaoALU,  int readData[], int writeRegister[]);
        ~EX_MEM();
        MEM_WB* start(int **dataMem);

};

#endif //EX_MEM_H_INCLUDED