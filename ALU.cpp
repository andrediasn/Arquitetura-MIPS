#include "ALU.h"                             // AINDA NAO MEXIDO, APENAS COPIADO DO CONTROLE.CPP

using namespace std;

ALU::ALU(){}

ALU::~ALU(){}

void ALU::attALU(int vet[]){
    for(int i = 0; i < 8; i++){
        this->entrada[i] = vet[i] ;
    }
    getAluOp();
    getFunctField();
    getSaida();

}


int* ALU::getAluOp() {
    this->aluOp[0] = entrada[0];
    this->aluOp[1] = entrada[1];
    return this->aluOp;
}

int* ALU::getFunctField() {
    for(int i = 2 ; i < 8 ; i++){
        this->functField[i] = entrada[i];
    }
    return this->functField;
}

int* ALU::getSaida() {
    if(aluOp[0] == 0 && aluOp[1] == 0){                  // lw ou sw
       this->aluSaida[0] = 0;
       this->aluSaida[1] = 0;
       this->aluSaida[2] = 1;
       this->aluSaida[3] = 0;
    }
    else if(aluOp[1] == 1){                      // beq
       this->aluSaida[0] = 0;
       this->aluSaida[1] = 1;
       this->aluSaida[2] = 1;
       this->aluSaida[3] = 0;
    }
    else {                      // R-Type
        if(functField[0] == 1 && functField[1] == 0 && functField[2] == 1 && functField[3] == 0){                              // set on less than
           this->aluSaida[0] = 0;
           this->aluSaida[1] = 1;
           this->aluSaida[2] = 1;
           this->aluSaida[3] = 1;
        }
        if(functField[0] == 0 && functField[1] == 1 && functField[2] == 0 && functField[3] == 1){        // OR
           this->aluSaida[0] = 0;
           this->aluSaida[1] = 0;
           this->aluSaida[2] = 0;
           this->aluSaida[3] = 1;
        }
        if(functField[0] == 0 && functField[1] == 1 && functField[2] == 0 && functField[3] == 0){     // AND
           this->aluSaida[0] = 0;
           this->aluSaida[1] = 0;
           this->aluSaida[2] = 0;
           this->aluSaida[3] = 0;
        }
        if(functField[0] == 0 && functField[1] == 0 && functField[2] == 1 && functField[3] == 0) {      // subtract
           this->aluSaida[0] = 0;
           this->aluSaida[1] = 1;
           this->aluSaida[2] = 1;
           this->aluSaida[3] = 0;
        }
        if(functField[0] == 0 && functField[1] == 0 && functField[2] == 0 && functField[3] == 0) {        // ADD
           this->aluSaida[0] = 0;
           this->aluSaida[1] = 0;
           this->aluSaida[2] = 1;
           this->aluSaida[3] = 0;
        }
    }
    return this->aluSaida;                
}
