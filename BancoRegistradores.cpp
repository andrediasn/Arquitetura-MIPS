#include "BancoRegistradores.h"

using namespace std;

BancoRegistradores::BancoRegistradores() {}
BancoRegistradores::~BancoRegistradores() {}

void BancoRegistradores::setReadData(int readRegister1[], int readRegister2[]){
    int id1 = 0, id2 = 0;
    // Transforma binario para inteiro para buscar o indice para buscar no Banco de Registradores
    for(int i = 0; i < 5; i++){ // rever
        id1 += readRegister1[i] * pow(2,4-i); 
        id2 += readRegister2[i] * pow(2,4-i);
    }
    
    cout << endl << id1 << " " << id2 << endl;
    // Copia conteudo do registrador para enviar para ID_EX
    for(int i = 0; i < 32; i++){
        this->readData1[i] = registradoresData[id1][i];
        this->readData2[i] = registradoresData[id2][i];
    }
}

int* BancoRegistradores::getReadData1(){
    return this->readData1;
}

int* BancoRegistradores::getReadData2(){
    return this->readData2;
}