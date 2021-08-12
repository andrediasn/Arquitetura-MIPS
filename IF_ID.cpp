#include <iostream>
#include "IF_ID.h"
#include "ID_EX.h"
#include "BancoRegistradores.h"
#include "Controle.h"
#include "OpLogicos.h"

using namespace std;

IF_ID::IF_ID(int memInst[], int PC){
    this->PC = PC;

    for(int i = 0; i < 8; i++)
        this->controle[i] = memInst[i];

    for(int i = 0; i < 16; i++)
        this->instruction_0_15[i] = memInst[i];

    for(int i = 11; i < 16; i++) 
        this->instruction_11_15[i] = memInst[i];

    for(int i = 16; i < 21; i++) 
        this->instruction_16_20[i] = memInst[i];

    toID_EX();
    toControle();
    toBancoRegistradores();
    toOpLogicos(); // rever o nome, talvez "Operadores Logicos"
}

IF_ID::~IF_ID(){}

void IF_ID::toID_EX(){
    ID_EX *idex = new ID_EX(this->PC, this->instruction_11_15, this->instruction_16_20);
}

void IF_ID::toControle(){
    Controle control;
    control.attControle(this->controle);
}

void IF_ID::toBancoRegistradores(){
    BancoRegistradores br;
    //br.attBancoRegistradores(this->readRegister1, this->readRegister2);
}

void IF_ID::toOpLogicos(){
    //OpLogicos op;
    //op.extSinal(this->instruction_0_15);
}

