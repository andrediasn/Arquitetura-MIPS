#ifndef BANCOREGISTRADORES_H_INCLUDED
#define BANCOREGISTRADORES_H_INCLUDED
#include <iostream>
#include <math.h>

class BancoRegistradores{
    private:

        int readData1[32]; // Registrador que sera enviado para ID_EX 
        int readData2[32]; // Registrador que sera enviado para ID_EX

    public:

        BancoRegistradores(){};
        ~BancoRegistradores(){};

        void setReadData(int readRegister1[], int readRegister2[], int **registers){ // Recebido de IF_ID
            int id1 = 0, id2 = 0;
            for(int i = 0; i < 5; i++){ // Transforma binario para inteiro para buscar o indice para buscar no Banco de Registradores
                id1 += readRegister1[i] * pow(2,4-i); 
                id2 += readRegister2[i] * pow(2,4-i);
            } // implementar tratamento de erro se for negativo
            
            for(int i = 0; i < 32; i++){ // Copia conteudo do registrador com indice id para enviar para ID_EX
                this->readData1[i] = registers[id1][i];
                this->readData2[i] = registers[id2][i];
            }
        } 

        int* getReadData1() { return this->readData1; } // Enviado para ID_EX
            
        
        int* getReadData2() { return this->readData2; } // Enviado para ID_EX

        void setRegisters(int writeRegister[], int writeData[], int **dataMem){
            int id = 0;
            for(int i = 0; i < 5; i++) // Transforma binario para inteiro para buscar o indice para buscar no Banco de Registradores
                id += writeRegister[i] * pow(2,4-i);

            for (int i = 0; i < 32; i++)
                dataMem[id][i] = writeData[i];
        }


};

#endif //BANCOREGISTRADORES_H_INCLUDED