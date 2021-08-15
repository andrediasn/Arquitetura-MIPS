#ifndef MEM_WB_H_INCLUDED
#define MEM_WB_H_INCLUDED
#include <iostream>
class MEM_WB{
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
        MEM_WB(int Aluresult[], int writeReg[], bool MemtoR, bool RegW);
        ~MEM_WB();
        int start(int **registers);

};

#endif //MEM_WB_H_INCLUDED