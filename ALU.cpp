#include "ALU.h"

using namespace std;

ALU::ALU(){}

ALU::~ALU(){}

void ALU::attAlu(int op[4],int reg1[32], int reg2[32]){
    for(int i = 0; i < 4; i++){
        operation[i] = op[i];
    }
    for(int i = 0; i < 32; i++){
        readData1[i] = reg1[i];
        readData2[i] = reg2[i];
    }    
}

void ALU::setAluResult(){
    if(operation[1] == 0 && operation[2] == 1 && operation[3] == 0) {            // operação de add
         // implementar
    }else if(operation[1] == 1 && operation[2] == 1 && operation[3] == 0){      // operação de sub 
        // implementar
    }else if(operation[1] == 0 && operation[2] == 0 && operation[3] == 0){      // operaçao AND
        // implementar
    }else if(operation[1] == 0 && operation[2] == 0 && operation[3] == 1){       // operação OR
        //implementar
    }else{                                                                      // operação set less than
        // implementar
    }
}

bool ALU::getZero() {return 0;}

int* ALU::getAluResult() {return aluResult;}

    
