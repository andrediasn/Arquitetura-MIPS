#ifndef EX_MEM_H_INCLUDED
#define EX_MEM_H_INCLUDED
#include <iostream>
#include "ALU.h"
#include "Controle.h"


class EX_MEM{
    private:
        int PC;
        int Desvio;
        bool zeroAlu;
        int ALUresult[32];
        int readData2[32];
        int writeRegister[5]; 
        bool MemtoReg;
        bool RegWrite;
        bool MemRead;
        bool MemWrite;
        bool Branch;
  
    public:
        EX_MEM(Controle control, int PC, int desvio, ALU operacaoALU,  int readData[], int writeRegister[]);
        ~EX_MEM();
        void start();

};

#endif //EX_MEM_H_INCLUDED