#include "OpLogicos.h"

using namespace std;
OpLogicos::OpLogicos(){}
OpLogicos::~OpLogicos(){}

void OpLogicos::extensorSinal(int vetIn[]){
    //cout << endl << " vet extender: "<< endl;
    //for(int i=0; i<16;i++) 
    //    cout <<vetIn[i];


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

    //cout << endl << " vet extendido: "<< endl;
    //for(int i=0; i<32;i++) 
    //    cout << vetExtSinal[i];
}

int* OpLogicos::getExtensorSinal(){
    return this->vetExtSinal;
}