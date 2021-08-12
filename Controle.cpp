#include "controle.h"
Controle::Controle(int vet[8]){
    for(int i = 0; i < 8; i++){
        entrada[i] = vet[i] ;
    }
    setAluOp();
    setFunctField();
    setSaida();
    
}

Controle::~Controle() { }

void Controle::setAluOp() {
    if(entrada[0] == 0 && entrada[1] == 0){
        aluOp[0] = 0;
        aluOp[1] = 0;
    }
    if(entrada[0] == 0 && entrada[1] == 1){
        aluOp[0] = 0;
        aluOp[1] = 1;
    }
    if(entrada[0] == 1){
        aluOp[0] = 1;
        aluOp[1] = 0;
    }

}

void Controle::setFunctField() {
    for(int i = 2 ; i < 8 ; i++){
        functField[i] = entrada[i];
    }
}

void Controle::setSaida() {
    if(aluOp[0] == 0 && aluOp[1] == 0){                      // lw ou sw
       aluSaida[0] = 0;
       aluSaida[1] = 0;
       aluSaida[2] = 1;
       aluSaida[3] = 0;
    }
    if(aluOp[0] == 1 && aluOp[1] == 1){                      // beq
       aluSaida[0] = 0;
       aluSaida[1] = 1;
       aluSaida[2] = 1;
       aluSaida[3] = 0;
    }
    if(aluOp[0] == 1 && aluOp[1] == 0){                      // R-Type
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
}


