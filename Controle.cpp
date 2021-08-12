#include "controle.h"

using namespace std;

Controle::Controle(){}

Controle::~Controle() {}

void Controle::attControle(int vet[]){
    for(int i = 0; i < 8; i++){
        entrada[i] = vet[i] ;
    }
    setAluOp();
    setFunctField();
    setSaida();

}


int* Controle::getAluOp() {
    aluOp[0] = entrada[0];
    aluOp[1] = entrada[1];
    return this->aluOpaluOp;
}

int* Controle::getFunctField() {
    for(int i = 2 ; i < 8 ; i++){
        functField[i] = entrada[i];
    }
    return this->functFieldfunctField;
}

int* Control::getSaida() {
    if(aluOp[0] == 0 && aluOp[1] == 0){                      // lw ou sw
       aluSaida[0] = 0;
       aluSaida[1] = 0;
       aluSaida[2] = 1;
       aluSaida[3] = 0;
    }
    else if(aluOp[1] == 1){                      // beq
       aluSaida[0] = 0;
       aluSaida[1] = 1;
       aluSaida[2] = 1;
       aluSaida[3] = 0;
    }
    else {                      // R-Type
        if(functField[2] == 1 && functField[3] == 0 && functField[4] == 1 && functField[4] == 0){                              // set on less than
           aluSaida[0] = 0;
           aluSaida[1] = 1;
           aluSaida[2] = 1;
           aluSaida[3] = 1;
        }
        if(functField[2] == 0 && functField[3] == 1 && functField[4] == 0 && functField[5] == 1){        // OR
           aluSaida[0] = 0;
           aluSaida[1] = 0;
           aluSaida[2] = 0;
           aluSaida[3] = 1;
        }
        if(functField[2] == 0 && functField[3] == 1 && functField[4] == 0 && functField[4] == 0){     // AND
           aluSaida[0] = 0;
           aluSaida[1] = 0;
           aluSaida[2] = 0;
           aluSaida[3] = 0;
        }
        if(functField[2] == 0 && functField[3] == 0 && functField[4] == 1 && functField[4] == 0) {      // subtract
           aluSaida[0] = 0;
           aluSaida[1] = 1;
           aluSaida[2] = 1;
           aluSaida[3] = 0;
        }
        if(functField[2] == 0 && functField[3] == 0 && functField[4] == 0 && functField[5] == 0) {        // ADD
           aluSaida[0] = 0;
           aluSaida[1] = 0;
           aluSaida[2] = 1;
           aluSaida[3] = 0;
        }
    }
    return this.aluSaida;                
}

