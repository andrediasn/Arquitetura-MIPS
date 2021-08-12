#include <iostream>
#include "ID_EX.h"
#include "Controle.h"
#include "OpLogicos.h"

using namespace std;

ID_EX::ID_EX(int PC, int instruction_11_15[], int instruction_16_20[]){
    this->PC = PC;
    for (int i = 0; i < 5; i++){
        this->instruction_11_15[i] = instruction_11_15[i];
        this->instruction_16_20[i] = instruction_16_20[i];
    }

    setControl();
    setReadData();
    setUniOperacional();
}

ID_EX::~ID_EX(){}

void ID_EX::setControl(){
    Controle control;

    
}

void ID_EX::setReadData() { 
        BancoRegistradores br;
        //int rd1[8] = br.getReadData1();
        //int rd2[8] = br.getReadData2()
        
        //for(int i = 0; i < 8; i++) {//confirmar ainda numero de bits
        //    this->readData1[i] = rd1[i]; 
        //    this->readData2[i] = rd2[i]; 
        //}
}

void ID_EX::setUniOperacional(){
    OpLogicos extSinal;
    extSinal.extensorSinal(this->instruction_0_15);
}

