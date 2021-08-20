#include "ID_EX.h"

using namespace std;

ID_EX::ID_EX(int PC, int instruction_15_11[], int instruction_20_16[], Controle control, BancoRegistradores reg, OpLogicos op){
    
        // ================   Escrevendo em ID_EX ===================== //
    std::cout << " -> Write ID_EX" << std::endl;
    this->PC = PC;  // get PC
    
    for (int i = 0; i < 5; i++){ 
        this->instruction_15_11[i] = instruction_15_11[i]; // get instruction_15_11
        this->instruction_20_16[i] = instruction_20_16[i]; // get instruction_20_16
    }

    // get control
    bool *auxControl = control.getRegDst();
    this->RegDst[0] = auxControl[0];
    this->RegDst[1] = auxControl[1];
    this->ALUSrc = control.getALUSrc();
    auxControl = control.getMemToReg();
    this->MemToReg[0] = auxControl[0];
    this->MemToReg[1] = auxControl[1]; 
    this->RegWrite = control.getRegWrite();
    this->MemRead = control.getMemRead();
    this->MemWrite = control.getMemWrite();
    this->Branch = control.getBranch();
    this->Bne = control.getBne();
    this->ALUOp0 = control.getALUOp0();
    this->ALUOp1 = control.getALUOp1();
    auxControl = control.getJump();
    this->Jump[0] = auxControl[0];
    this->Jump[1] = auxControl[1]; 
    this->control = control;

    // get Registradores
    int *r1 = reg.getReadData1();
    int *r2 = reg.getReadData2();
    for (int i = 0; i < 32; i++){
        this->readData1[i] = r1[i];
        this->readData2[i] = r2[i];
    }

   
    int *auxExt = op.getExtensorSinal(); // get instruction_15_0 extendido
    int *auxJump = op.getVetJump();
    for (int i = 0; i < 32; i++){
        this->extend_15_0[i] = auxExt[i];
        this->desvioJump[i] = auxJump[i]; // erro
    }
    for(int i = 0; i < 6; i++)  
        this->funct[i] = extend_15_0[i+26];

}

ID_EX::~ID_EX(){}

        // ================= INICIA ETAPA 3 ================ //

EX_MEM* ID_EX::start(){

            // ================ Lendo de ID_EX =================== //
    std::cout << " -> Read ID_EX" << std::endl;

    OpLogicos op;
    int *desvioBeq = new int[32]; // Enviado para deslocamento
    desvioBeq = op.shiftLeft(this->extend_15_0, 2, desvioBeq);

    int desvio = op.ADD(this->PC, desvioBeq);     // Envia PC e Desvio pro ADD

    int *toALU;     // Enviado para MUX e depois ALU e depois EX_MEM
    toALU = op.mutiplexador(this->readData2, this->extend_15_0, this->ALUSrc);

    ALUcontrol control; 
    int *operation;     // Enviado para ALUControl e depois ALU e depois EX_MEM
    operation = control.getOperation(this->funct, this->ALUOp1, this->ALUOp0);

    ALU operacaoALU; 
    operacaoALU.setAluResult(operation, this->readData1, toALU);    // Enviado para EX_MEM

    int ra[5];
    for (int i=0;i<5;i++)
        ra[i] = 1;

    int *writeRegister;     // Enviado para MUX e depois para EX_MEM
    writeRegister = op.mutiplexador3(this->instruction_20_16, ra, this->instruction_15_11, this->RegDst);

            // ================ Escreve em EX_MEM =================== //
    
    EX_MEM* exmem = new EX_MEM(this->control, this->PC, desvio, this->desvioJump, operacaoALU, this->readData1, this->readData2, writeRegister);
    
    return exmem;
}

