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
    this->aluOpaluOp[0] = entrada[0];
    this->aluOpaluOp[1] = entrada[1];
    return this->aluOpaluOp;
}

int* Controle::getFunctField() {
    for(int i = 4 ; i < 9 ; i++){
        this->functFieldfunctField[i] = entrada[i];
    }
    return this->functFieldfunctField;
}

int* Control::getSaida() {
    if(aluOp[0] == 0 && aluOp[1] == 0){                      // lw ou sw
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
    return this.aluSaida;                
}

