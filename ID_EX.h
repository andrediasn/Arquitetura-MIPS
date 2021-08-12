#ifndef ID_EX_H_INCLUDED
#define ID_EX_H_INCLUDED
#include "BancoRegistradores.h"

class ID_EX{
    private:
    int PC;
    int EX[3];
    int MEM;
    int WB;
    int instruction_20_11[10];
    int readData1[8];
    int readData2[8];

    public:
    ID_EX(){};
    ~ID_EX();
             
    void setFromID(int PC, int instruction_20_11[]){
        this->PC = PC;
        for(int i = 0; i <11; i++)
            this->instruction_20_11[i] = instruction_20_11[i];
    }

    void setReadData(int readData1[], int readData2[]) { 
        for(int i = 0; i < 8; i++) {//confirmar ainda numero de bits
            this->readData1[i] = readData1[i]; 
            this->readData2[i] = readData2[i]; 
        }
    }


    
};

#endif //ID_EX_H_INCLUDED