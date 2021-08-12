#include <iostream>
#include "IF_ID.h"
#include "BancoRegistradores.h"
#include "Controle.h"
#include "ID_EX.h"

using namespace std;

IF_ID::IF_ID(){}
IF_ID::~IF_ID(){}

void IF_ID::novaInstrucao(int memInst[], int PC){
    int aluControl[8];
    for(int i = 0; i < 8; i++)
        aluControl[i] = memInst[i];
    //Controle instrucao;
    // instrucao.aloOP(aluControl)
    
    ID_EX idex;
    int instruction_11_20[10];
    for(int i = 11; i < 21; i++)
        instruction_11_20[i-11] = memInst[i];
        
    idex.setFromID(PC, instruction_11_20);




}