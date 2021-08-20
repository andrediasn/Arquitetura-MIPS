#include "EX_MEM.h"


EX_MEM::EX_MEM(Controle control, int PC, int desvio, int jump[], ALU operacaoALU, int readData1[], int readData2[], int writeRegister[]){

        // ================   Escrevendo em EX_MEM ===================== //
    ofstream arq("saida.txt", ios::app);
    cout << " -> Write EX_MEM" << endl;
    arq << " -> Write EX_MEM" << endl;
    arq.close();
    this->PC = PC;  // get PC
    this->desvio = desvio; // get desvio

    // get from ALU
    this->zeroAlu = operacaoALU.getZeroAlu();
    int *aux = operacaoALU.getAluResult();
    
    for(int i = 0; i <32;i++){
        this->ALUresult[i] = aux[i];
        this->readData1[i] = readData1[i];
        this->readData2[i] = readData2[i];// get Registrador2 from ID_EX
        this->jump[i] = jump[i];
    }

    for(int i = 0; i < 5; i++)
        this->writeRegister[i] = writeRegister[i]; // get writeRegister

    // gets sinais de controle
    bool *auxMem = control.getMemToReg();
    this->MemToReg[0] = auxMem[0];
    this->MemToReg[1] = auxMem[1];
    this->RegWrite = control.getRegWrite();
    this->MemRead = control.getMemRead();
    this->MemWrite = control.getMemWrite();
    this->Branch = control.getBranch();
    auxMem = control.getJump();  
    this->Jump[0] = auxMem[0];
    this->Jump[1] = auxMem[1];
    this->Bne = control.getBne();
}
        
EX_MEM::~EX_MEM(){}

        // ================= INICIA ETAPA 4 ================ //

MEM_WB* EX_MEM::start(int **dataMem){

            // ================   Lendo de EX_MEM ===================== //
    printSinais();

    ofstream arq("saida.txt", ios::app);
    cout << " -> Read EX_MEM" << endl;
    arq << " -> Read EX_MEM" << endl;
    arq.close();

    OpLogicos op; 
    bool PCSrc = op.AND(this->Branch, this->zeroAlu); // gera indicador se vai haver desvio beq
    bool andBneZero = op.AND(this->Bne, !(this->zeroAlu)); // gera indicador se vai haver desvio bne
    bool orPC = op.OR(PCSrc, andBneZero); // gera indicador se vai haver desvio beq ou bne
    

    int *PCbin = new int[32];
    PCbin = op.toBinary(this->PC, PCbin);
    
    DataMemory datam;
    datam.setDataMemory(this->MemRead, this->MemWrite, this->ALUresult, this->readData2, dataMem);   // enviando pro datamemory

    this->PC = op.muxPC(this->PC, this->desvio, orPC); // pc+4 ou desvio beq

    this->desvio = 0; // pc+4 ou desvio jump
    for(int i = 0; i < 32; i++)
        this->desvio += this->jump[i] * pow(2,31-i); 

    int jr = 0;
    for(int i = 0; i < 32; i++)
        jr += this->readData1[i] * pow(2,31-i); 
    this->PC = op.muxPC(this->PC, jr, this->desvio, this->Jump);

            // ================ Escreve em MEM_WB ===================== //

    MEM_WB* memwb = new MEM_WB(this->ALUresult, this->writeRegister, datam, this->MemToReg, this->RegWrite, this->PC, PCbin); 
    return memwb;
}

void EX_MEM::printSinais(){
    ofstream arq("saida.txt", ios::app);
    arq << "Sinais de controle:" << endl;
    arq << "MemWrite = "<< this->MemWrite << endl;
    arq << "MemRead = "<< this->MemRead << endl;
    arq << "Branch = "<< this->Branch << endl;
    arq << "ZeroAlu = "<< this->zeroAlu << endl;
    arq << "Bne = " << this->Bne << endl;
    arq << "jump0 = " << this->Jump[0] << endl;
    arq << "jump1 = " << this->Jump[1] << endl;
    arq << endl;
    arq.close();
}





