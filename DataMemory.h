#ifndef DATAMEMORY_H_INCLUDED                                       
#define DATAMEMORY_H_INCLUDED
#include <math.h>
class DataMemory{

    private:
    bool memRead;         
    bool memWrite;
    int readData[32];        // é a saida
    int writeData[32]; // é uma entrada (conteudo)
    int address[32];

    
    public:
    DataMemory();
    ~DataMemory();

    void setDataMemory(bool mRead, bool mWrite, int aluResult[32], int wData[32], int **data){    // memread, memwrite, aluresult(endereço), conteudo, memoria de dados
        memRead = mRead;
        memWrite = mWrite;
        for(int i = 0; i < 32; i++){
            writeData[i] = wData[i];
            address[i] = aluResult[i];
        }
        int id;            // endereço em inteiro
        // transformar o endereço em um numero inteiro e colocar no int id

        for(int i = 0; i < 32; i++){
           id += address[i] * pow(2,31-i);
        }
        if(memRead){          // o valor de address tem q ser colocado em readData
            for(int i = 0;i < 32; i++){
             readData[i] = data[id][i];
            }
        }else if(memWrite) {               // valor de writeData vai ser armazenada em address
            for(int i = 0; i < 32; i++){
                data[id][i] = writeData[i];
            }

        }
    }

    int *getReadData() {return readData;}


};
#endif // DATAMEMORY_H_INCLUDED