#include "MEM_WB.h"

MEM_WB::MEM_WB(int Aluresult[], int writeReg[], DataMemory dataM, bool MemToReg[], bool RegWrite, int PC, int pcbin[]){

        // ================   Escrevendo em MEM_WB ===================== //
    ofstream arq("saida.txt", ios::app);
    cout << " -> Write MEM_WB" << endl;
    arq << " -> Write MEM_WB" << endl; 
    arq.close();

    this->MemToReg[0] = MemToReg[0];
    this->MemToReg[1] = MemToReg[1];
    this->RegWrite = RegWrite;

    int *readData2 = dataM.getReadData();

    for(int i = 0; i <32;i++){
        this->ALUresult[i] = Aluresult[i];
        this->readData[i] = readData2[i];
        this->PCbin[i] = pcbin[i];
    }
    for(int i = 0; i < 5; i++)
        this->writeRegister[i] = writeReg[i];

    this->PC = PC;


}

MEM_WB::~MEM_WB(){}

        // ================= INICIA ETAPA 5 ================ //

int MEM_WB::start(int **registers){

            // ================   Lendo de MEM_WB ===================== //
    printSinais();
    
    ofstream arq("saida.txt", ios::app);
    cout << " -> Read MEM_WB" << endl;
    arq << " -> Read MEM_WB" << endl;
    arq.close();
    
    OpLogicos mux;
    int *writeData;
    writeData = mux.mutiplexador3(this->ALUresult, this-> PCbin, this->readData, this->MemToReg);

    BancoRegistradores reg;
    reg.setRegisters(this->writeRegister, writeData, registers);

    return this->PC; // Devolve PC para main
}

void MEM_WB::printSinais(){
    ofstream arq("saida.txt", ios::app);
    arq << "Sinais de controle:" << endl;
    arq << "RegWrite = "<< this->RegWrite << endl;
    arq << "MemToReg0 = "<< this->MemToReg[0] << endl;
    arq << "MemToReg1 = "<< this->MemToReg[1] << endl;
    arq << endl;
    arq.close();
}