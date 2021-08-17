#include "EX_MEM.h"


EX_MEM::EX_MEM(Controle control, int PC, int desvio, ALU operacaoALU,  int readData[], int writeRegister[]){

        // ================   Escrevendo em EX_MEM ===================== //

    this->PC = PC;  // get PC
    this->Desvio = desvio; // get desvio

    // get from ALU
    this->zeroAlu = operacaoALU.getAluResult();
    int *aux = operacaoALU.getAluResult();
    
    for(int i = 0; i <32;i++){
        this->ALUresult[i] = aux[i];
        this->readData2[i] = readData[i];// get Registrador2 from ID_EX
    }

    for(int i = 0; i < 5; i++)
        this->writeRegister[i] = writeRegister[i]; // get writeRegister

    // gets sinais de controle
    this->MemToReg = control.getMemToReg();
    this->RegWrite = control.getRegWrite();
    this->MemRead = control.getMemRead();
    this->MemWrite = control.getMemWrite();
    this->Branch = control.getBranch();    
}
        
EX_MEM::~EX_MEM(){}

        // ================= INICIA ETAPA 4 ================ //

MEM_WB* EX_MEM::start(int **dataMem){

            // ================   Lendo de EX_MEM ===================== //

    DataMemory datam;
    datam.setDataMemory(this->MemRead, this->MemWrite, this->ALUresult, this->readData2, dataMem);   // enviando pro datamemory

    bool PCSrc;
    OpLogicos op; 
    PCSrc = op.AND(this->Branch, this->zeroAlu); 

    this->PC = op.muxPC(this->PC, this->Desvio, PCSrc);

            // ================ Escreve em MEM_WB ===================== //

    MEM_WB* memwb = new MEM_WB(this->ALUresult, this->writeRegister, this->readData2, this->MemToReg, this->RegWrite, this->PC); 
    return memwb;
}







