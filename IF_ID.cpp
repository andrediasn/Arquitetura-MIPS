#include "IF_ID.h"

using namespace std;

IF_ID::IF_ID(int memInst[], int PC){
    this->PC = PC;


    for(int i = 31; i > 25; i--)
        this->controle[i-26] = memInst[i];  // Ex: controle[5] = memInst[31]

    for(int i = 15; i > -1; i--)
        this->instruction_15_0[i] = memInst[i]; // Ex: instruction_15_0[15] = memInst[15]

    for(int i = 15; i > 10; i--) 
        this->instruction_15_11[i-11] = memInst[i]; // Ex: instruction_15_11[4] = memInst[15]

    for(int i = 20; i > 15; i--) 
        this->instruction_20_16[i-16] = memInst[i]; // Ex: instruction_20_16[4] = memInst[20]

    start();
    
}

IF_ID::~IF_ID(){}

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

void IF_ID::start(){
    toID_EX();
    toControlePrincipal();
    toBancoRegistradores();
    toOpLogicos();
}

