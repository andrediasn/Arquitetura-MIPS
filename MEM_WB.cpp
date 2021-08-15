#include "MEM_WB.h"

MEM_WB::MEM_WB(int Aluresult[], int writeReg[], bool MemtoR, bool RegW){
    MemtoReg = MemtoR;
    RegWrite = RegW;
    for(int i = 0; i <32;i++){
        this->ALUresult[i] = Aluresult[i];
        this->
    }


}
MEM_WB::~MEM_WB(){}
