#include "ID_EX.h"

using namespace std;

ID_EX::ID_EX(int PC, int instruction_15_11[], int instruction_20_16[]){
    this->PC = PC;
    for (int i = 0; i < 5; i++){
        this->instruction_15_11[i] = instruction_15_11[i];
        this->instruction_20_16[i] = instruction_20_16[i];
    }

    // certo acima

    setReadData(); // pegando lixo
    setControl(); // pegando lixo
    setExtSinal(); // pegando lixo

    //for (int i = 0; i < 32; i++)
    //    cout << instruction_15_0[i];
    //cout << endl;


}

ID_EX::~ID_EX(){}

void ID_EX::setControl(){ // pegando lixo
    Controle control;
    this->RegDst = control.getRegDst();
    this->ALUSrc = control.getALUSrc();
    this->MemtoReg = control.getMemtoReg();
    this->RegWrite = control.getRegWrite();
    this->MemRead = control.getMemRead();
    this->MemWrite = control.getMemWrite();
    this->Branch = control.getBranch();
    this->ALUOp0 = control.getALUOp0();
    this->ALUOp1 = control.getALUOp1();
}

void ID_EX::setExtSinal() { // pegando lixo
    OpLogicos sinalExt;
    int *aux = sinalExt.getExtensorSinal();
    for (int i = 0; i < 32; i++)
        this->instruction_15_0[i] = aux[i];
}

void ID_EX::setReadData() {  // pegando lixo
    BancoRegistradores registrador;
    int *r1 = registrador.getReadData1();
    int *r2 = registrador.getReadData2();
    
    for (int i = 0; i < 32; i++){
        this->readData1[i] = r1[i];
        this->readData2[i] = r2[i];
    }
}

ID_EX* ID_EX::get(){
    return this;
}


void ID_EX::start(){
    cout << endl;
    for (int i = 0; i < 32; i++)
        cout << instruction_15_0[i];
    cout << endl;

}

