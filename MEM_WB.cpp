#include "MEM_WB.h"

MEM_WB::MEM_WB(int Aluresult[], int writeReg[], DataMemory dataM, bool MemToReg, bool RegWrite, int PC){

        // ================   Escrevendo em MEM_WB ===================== //
    std::cout << " -> Write MEM_WB" << std::endl;

    this->MemToReg = MemToReg;
    this->RegWrite = RegWrite;

    int *readData2 = dataM.getReadData();

    for(int i = 0; i <32;i++){
        this->ALUresult[i] = Aluresult[i];
        this->readData[i] = readData2[i];
    }
    for(int i = 0; i < 5; i++)
        this->writeRegister[i] = writeReg[i];

    this->PC = PC;
}

MEM_WB::~MEM_WB(){}

        // ================= INICIA ETAPA 5 ================ //

int MEM_WB::start(int **registers){

            // ================   Lendo de MEM_WB ===================== //
    std::cout << " -> Read MEM_WB" << std::endl;
    
    OpLogicos mux;
    int *writeData;
    writeData = mux.mutiplexador(this->ALUresult, this->readData, this->MemToReg);

    BancoRegistradores reg;
    reg.setRegisters(this->writeRegister, writeData, registers);

    return this->PC; // Devolve PC para main
}
