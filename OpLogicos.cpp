#include "OpLogicos.h"

using namespace std;
OpLogicos::OpLogicos(){}
OpLogicos::~OpLogicos(){}

void OpLogicos::extensorSinal(int vetIn[]){
    if(vetIn[0]==0){
        for(int i=0;i<16;i++)
            this->vetExtSinal[i] = 0;
        for(int i=16;i<32;i++)  
            this->vetExtSinal[i] = vetIn[i-16];
    }
    else{
        for(int i=0;i<16;i++)
            this->vetExtSinal[i] = 1;
        for(int i=16;i<32;i++)  
            this->vetExtSinal[i] = vetIn[i-16];
    }

    // Funcionando corretamente
}

int* OpLogicos::getExtensorSinal(){
    return this->vetExtSinal;
}