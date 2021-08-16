#include "MEM_WB.h"

MEM_WB::MEM_WB(int Aluresult[], int writeReg[], int readData2[], bool MemToReg, bool RegWrite, int PC){

        // ================   Escrevendo em MEM_WB ===================== //

    this->MemToReg = MemToReg;
    this->RegWrite = RegWrite;
    for(int i = 0; i <32;i++){
        this->ALUresult[i] = Aluresult[i];
        this->readData2[i] = readData2[i];
    }
    for(int i = 0; i < 5; i++)
        this->writeRegister[i] = writeReg[i];

    this->PC = PC;
}

MEM_WB::~MEM_WB(){}

        // ================= INICIA ETAPA 5 ================ //

int MEM_WB::start(int **registers){

            // ================   Lendo de MEM_WB ===================== //

    OpLogicos mux;
    int *writeData;
    writeData = mux.mutiplexador(this->ALUresult, this->readData2, this->MemToReg);

    BancoRegistradores reg;
    reg.setRegisters(this->writeRegister, writeData, registers);

    return this->PC; // Devolve PC para main
}
