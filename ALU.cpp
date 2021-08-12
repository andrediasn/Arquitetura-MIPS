#include "ALU.h"                             

using namespace std;

ALU::ALU(){}

ALU::~ALU(){}

void ALU::attALU(int vet[], bool Op1, bool Op0){                               // precisa do vetor funct e do aluOp1 e aluOp0
    for(int i = 0; i < 6; i++){
        this->functField[i] = vet[i];
    }
    ALUOp1 = Op1;
    ALUOp0 = Op0;
}

int* ALU::getOperation() {
    if(ALUOp0 == 0 && ALUOp1 == 0){                  // lw ou sw
       this->Operation[0] = 0;
       this->Operation[1] = 0;
       this->Operation[2] = 1;
       this->Operation[3] = 0;
    }
    else if(ALUOp0 == 1){                      // beq
       this->Operation[0] = 0;
       this->Operation[1] = 1;
       this->Operation[2] = 1;
       this->Operation[3] = 0;
    }
    else {                      // R-Type
        if(functField[3] == 1 && functField[2] == 0 && functField[1] == 1 && functField[0] == 0){                              // set on less than
           this->Operation[0] = 0;
           this->Operation[1] = 1;
           this->Operation[2] = 1;
           this->Operation[3] = 1;
        }
        if(functField[3] == 0 && functField[2] == 1 && functField[1] == 0 && functField[0] == 1){        // OR
           this->Operation[0] = 0;
           this->Operation[1] = 0;
           this->Operation[2] = 0;
           this->Operation[3] = 1;
        }
        if(functField[3] == 0 && functField[2] == 1 && functField[1] == 0 && functField[0] == 0){     // AND
           this->Operation[0] = 0;
           this->Operation[1] = 0;
           this->Operation[2] = 0;
           this->Operation[3] = 0;
        }
        if(functField[3] == 0 && functField[2] == 0 && functField[1] == 1 && functField[0] == 0) {      // subtract
           this->Operation[0] = 0;
           this->Operation[1] = 1;
           this->Operation[2] = 1;
           this->Operation[3] = 0;
        }
        if(functField[3] == 0 && functField[2] == 0 && functField[1] == 0 && functField[0] == 0) {        // ADD
           this->Operation[0] = 0;
           this->Operation[1] = 0;
           this->Operation[2] = 1;
           this->Operation[3] = 0;
        }
    }
    return this->Operation;                
}
