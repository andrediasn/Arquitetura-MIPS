#ifndef MEM_WB_H_INCLUDED
#define MEM_WB_H_INCLUDED
#include <iostream>
#include "OpLogicos.h"
#include "BancoRegistradores.h"
#include "DataMemory.h"

class MEM_WB{
    private:
        bool zeroAlu;
        int ALUresult[32];
        int readData[32];
        int writeRegister[5]; 
        bool MemToReg;
        bool RegWrite;
        int PC;
  
    public:
        MEM_WB(int Aluresult[], int writeReg[], DataMemory dataM, bool MemToReg, bool RegWrite, int PC);
        ~MEM_WB();
        int start(int **registers);

};

#endif //MEM_WB_H_INCLUDED