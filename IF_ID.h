#ifndef IF_ID_H_INCLUDED
#define IF_ID_H_INCLUDED
#include <iostream>
#include <fstream>
#include "ID_EX.h"
#include "BancoRegistradores.h"
#include "Controle.h"
#include "OpLogicos.h"

using namespace std;
class IF_ID{
    private:
    int PC;
    int controle[6]; // Bits 31-26 do Para a unidade de controle
    int instruction_15_0[16]; // Para Extensor de Sinal
    int instruction_10_6[5];  // campo Shamt
    int instruction_20_16[5]; // Para ID_Ex
    int instruction_15_11[5]; // Para ID_EX
    int instruction_5_0[6];   // functfield
    int readRegister1[5]; // Bits 25-21 para Banco de Registradores
    int readRegister2[5]; // Bits 20-16 para banco de registradores
    int jump_25_0[26]; // Bits 25-0 para calcular desvio do Jump
        
    public:
        IF_ID(int memInst[], int PC);
        ~IF_ID();
        ID_EX* start(int **registers);

};

#endif //IF_ID_H_INCLUDED