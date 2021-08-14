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
        MEM_WB();
        ~MEM_WB();
        //MEM_WB* start();

};

#endif //MEM_WB_H_INCLUDED