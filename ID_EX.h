#ifndef ID_EX_H_INCLUDED
#define ID_EX_H_INCLUDED
#include "BancoRegistradores.h"

class ID_EX{
    private:
        int PC;
        int EX[3];
        int MEM;
        int WB;
        int instruction_0_15[32]; // Apos extensao de sinal
        int instruction_11_15[5];
        int instruction_16_20[5];
        int readData1[8];
        int readData2[8];

        void setReadData();
        void setControl();
        void setUniOperacional();
    
    
    public:
        ID_EX(int PC, int instruction_11_15[], int instruction_16_20[]);
        ~ID_EX();
             
    

    
};

#endif //ID_EX_H_INCLUDED