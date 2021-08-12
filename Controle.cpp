#include "controle.h"

using namespace std;

Controle::Controle(){}

Controle::~Controle(){}

void Controle::attControle(int vet[]){
    for(int i = 0; i < 6; i++){
        this->Op[i] = vet[i] ;
    }
    getAllSaida();
}


int Controle::getAllSaida() {
    if(Op[5] == 1 && Op[3] == 0){                // é uma operação LW
       this->RegDst = 0;
       this->ALUSrc = 1;
       this->MemtoReg = 1;
       this->RegWrite = 1;
       this->MemRead = 1;
       this->MemWrite = 0;
       this->Branch = 0;
       this->ALUOp1 = 0;
       this->ALUOp0 = 0;
    }else if(Op[5] == 1 && Op[3] == 1){                 // é uma operação SW
       this->ALUSrc = 1;
       this->RegWrite = 0;
       this->MemRead = 0;
       this->MemWrite = 1;
       this->Branch = 0;
       this->ALUOp1 = 0;
       this->ALUOp0 = 0;
    }else if {Op[2] == 1} {                          // é uma operaçao BEQ
       this->ALUSrc = 0;
       this->RegWrite = 0;
       this->MemRead = 0;
       this->MemWrite = 0;
       this->Branch = 1;
       this->ALUOp1 = 0;
       this->ALUOp0 = 1;
    }else {                                          // é uma operaçao tipo R
       this->RegDst = 1;
       this->ALUSrc = 0;
       this->MemtoReg = 0;
       this->RegWrite = 1;
       this->MemRead = 0;
       this->MemWrite = 0;
       this->Branch = 0;
       this->ALUOp1 = 1;
       this->ALUOp0 = 0;
    }
    struct result {int ; int ;};   
    
}



