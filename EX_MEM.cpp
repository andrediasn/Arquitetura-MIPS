#include "EX_MEM.h"


EX_MEM::EX_MEM(Controle control, int PC, int desvio, int jump[], ALU operacaoALU,  int readData[], int writeRegister[]){

        // ================   Escrevendo em EX_MEM ===================== //
    std::cout << " -> Write EX_MEM" << std::endl;
    this->PC = PC;  // get PC
    this->desvio = desvio; // get desvio

    // get from ALU
    this->zeroAlu = operacaoALU.getAluResult();
    int *aux = operacaoALU.getAluResult();
    
    for(int i = 0; i <32;i++){
        this->ALUresult[i] = aux[i];
        this->readData2[i] = readData[i];// get Registrador2 from ID_EX
        this->jump[i] = jump[i];
    }

    for(int i = 0; i < 5; i++)
        this->writeRegister[i] = writeRegister[i]; // get writeRegister

    // gets sinais de controle
    this->MemToReg = control.getMemToReg();
    this->RegWrite = control.getRegWrite();
    this->MemRead = control.getMemRead();
    this->MemWrite = control.getMemWrite();
    this->Branch = control.getBranch();
    this->Jump = control.getJump();  
}
        
EX_MEM::~EX_MEM(){}

        // ================= INICIA ETAPA 4 ================ //

MEM_WB* EX_MEM::start(int **dataMem){

            // ================   Lendo de EX_MEM ===================== //
    std::cout << " -> Read EX_MEM" << std::endl;

    OpLogicos op; 
    bool PCSrc = op.AND(this->Branch, this->zeroAlu); 
    
    DataMemory datam;
    datam.setDataMemory(this->MemRead, this->MemWrite, this->ALUresult, this->readData2, dataMem);   // enviando pro datamemory

    this->PC = op.muxPC(this->PC, this->desvio, PCSrc);

    desvio = op.ADD(this->PC, this->jump); 
    this->PC = op.muxPC(this->PC, this->desvio, this->Jump);

            // ================ Escreve em MEM_WB ===================== //

    MEM_WB* memwb = new MEM_WB(this->ALUresult, this->writeRegister, datam, this->MemToReg, this->RegWrite, this->PC); 
    return memwb;
}







