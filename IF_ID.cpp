#include "IF_ID.h"

using namespace std;

IF_ID::IF_ID(int memInst[], int PC){
    this->PC = PC;
    for(int i = 0; i < 6; i++)
        this->controle[5-i] = memInst[i];  // Ex: i=0 -> controle[5] = memInst[0] | i=1 -> controle[4] = memInst[1]
        //[i] = [i] se for padronizado

    for(int i = 0; i < 5; i++)
        this->readRegister1[i] =  memInst[i+6]; // Ex: readRegister1[0] =  memInst[6] | readRegister1[4] =  memInst[10]

    for(int i = 0; i < 5; i++)
        this->readRegister2[i] =  memInst[i+11]; // Ex: readRegister2[0] =  memInst[11] | readRegister2[4] =  memInst[15]

    for(int i = 0; i < 16; i++)
        this->instruction_15_0[i] = memInst[i+16]; // Ex: instruction_15_0[0] = memInst[16] | instruction_15_0[15] = memInst[31]

    for(int i = 0; i < 5; i++) 
        this->instruction_20_16[i] = memInst[i+11]; // Ex: instruction_20_16[0] = memInst[11] | instruction_20_16[4] = memInst[15]
    
    for(int i = 0; i < 5; i++) 
        this->instruction_15_11[i] = memInst[i+16]; // Ex: instruction_15_11[0] = memInst[16] | instruction_15_11[4] = memInst[20]
}

IF_ID::~IF_ID(){}

void IF_ID::start(){
    toControlePrincipal(); // bit 31-26
    toBancoRegistradores(); // bit 25-21 e 20-16
    toOpLogicos(); // bit 15-0
    toID_EX(); // bit 20-16 e 15-11
}

void IF_ID::toID_EX(){
    ID_EX *idex = new ID_EX(this->PC, this->instruction_15_11, this->instruction_20_16);
}

void IF_ID::toControlePrincipal(){
    Controle control;
    control.attControle(this->controle);
}

void IF_ID::toBancoRegistradores(){
    BancoRegistradores readData;
    readData.setReadData(this->readRegister1, this->readRegister2);
}

void IF_ID::toOpLogicos(){
    OpLogicos extSinal;
    extSinal.extensorSinal(this->instruction_15_0);
}


