#include "ID_EX.h"

using namespace std;

ID_EX::ID_EX(int PC, int instruction_15_11[], int instruction_20_16[], Controle control, BancoRegistradores reg, OpLogicos extSinal){
    
        // ================   Escrevendo em ID_EX ===================== //

    this->PC = PC;  // get PC
    
    for (int i = 0; i < 5; i++){ 
        this->instruction_15_11[i] = instruction_15_11[i]; // get instruction_15_11
        this->instruction_20_16[i] = instruction_20_16[i]; // get instruction_20_16
    }

    // get control
    this->RegDst = control.getRegDst();
    this->ALUSrc = control.getALUSrc();
    this->MemToReg = control.getMemToReg();
    this->RegWrite = control.getRegWrite();
    this->MemRead = control.getMemRead();
    this->MemWrite = control.getMemWrite();
    this->Branch = control.getBranch();
    this->ALUOp0 = control.getALUOp0();
    this->ALUOp1 = control.getALUOp1();
    this->control = control;

    // get Registradores
    int *r1 = reg.getReadData1();
    int *r2 = reg.getReadData2();
    for (int i = 0; i < 32; i++){
        this->readData1[i] = r1[i];
        this->readData2[i] = r2[i];
    }

    // get instruction_15_0 extendido
    int *aux = extSinal.getExtensorSinal();
    for (int i = 0; i < 32; i++)
        this->instruction_15_0[i] = aux[i];
}

ID_EX::~ID_EX(){}

        // ================= INICIA ETAPA 3 ================ //

EX_MEM* ID_EX::start(){

            // ================ Lendo de ID_EX =================== //

    OpLogicos op;
    int *jump; // Enviado para deslocamento
    jump = op.shiftLeft(this->instruction_15_0, 2);

    int desvio = op.ADD(this->PC, jump);     // Envia PC e Desvio pro ADD

    int *toALU;     // Enviado para MUX e depois ALU e depois EX_MEM
    toALU = op.mutiplexador(this->readData2, this->instruction_15_0, this->ALUSrc);

    ALUcontrol control; 
    int *operation;     // Enviado para ALUControl e depois ALU e depois EX_MEM
    operation = control.getOperation(this->funct, this->ALUOp1, this->ALUOp0);

    ALU operacaoALU; 
    operacaoALU.setAluResult(operation, this->readData1, toALU);    // Enviado para EX_MEM


    int *writeRegister;     // Enviado para MUX e depois para EX_MEM
    writeRegister = op.mutiplexador(this->instruction_20_16, this->instruction_15_11, this->RegDst);

            // ================ Escreve em EX_MEM =================== //
    
    EX_MEM* exmem = new EX_MEM(this->control, this->PC, desvio, operacaoALU, this->readData2, writeRegister);
    
    return exmem;
}

