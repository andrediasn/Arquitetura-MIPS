#include "OpLogicos.h"
#include <iostream>

OpLogicos::OpLogicos(){}
OpLogicos::~OpLogicos(){}

int* OpLogicos::extensorSinal(int vetIn[]){
    int vetOut[32];
    if(vetIn[0]==0){
        for(int i=0;i<16;i++)
            vetOut[i] = 0;
        for(int i=16;i<32;i++)  
            vetOut[i] = vetIn[i];
    }
    else{
        for(int i=0;i<16;i++)
            vetOut[i] = 1;
        for(int i=16;i<32;i++)  
            vetOut[i] = vetIn[i];
    }
    return vetOut;
}