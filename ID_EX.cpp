#include "ID_EX.h"

using namespace std;

ID_EX::ID_EX(int PC, int instruction_15_11[], int instruction_20_16[]){
    this->PC = PC;
    for (int i = 0; i < 5; i++){
        this->instruction_15_11[i] = instruction_15_11[i];
        this->instruction_20_16[i] = instruction_20_16[i];
    }
}

ID_EX::~ID_EX(){}

void ID_EX::setControl(Controle control){ // pegando lixo
    this->RegDst = control.getRegDst();
    this->ALUSrc = control.getALUSrc();
    this->MemtoReg = control.getMemtoReg();
    this->RegWrite = control.getRegWrite();
    this->MemRead = control.getMemRead();
    this->MemWrite = control.getMemWrite();
    this->Branch = control.getBranch();
    this->ALUOp0 = control.getALUOp0();
    this->ALUOp1 = control.getALUOp1();
}

void ID_EX::setExtSinal(OpLogicos extSinal) { // pegando lixo
    int *aux = extSinal.getExtensorSinal();
    for (int i = 0; i < 32; i++)
        this->instruction_15_0[i] = aux[i];
}

void ID_EX::setReadData(BancoRegistradores reg) {  // pegando lixo
    int *r1 = reg.getReadData1();
    int *r2 = reg.getReadData2();
    
    for (int i = 0; i < 32; i++){
        this->readData1[i] = r1[i];
        this->readData2[i] = r2[i];
    }
}


void ID_EX::start(){
    
}

