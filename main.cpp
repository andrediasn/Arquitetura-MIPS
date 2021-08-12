#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "IF_ID.h"


using namespace std;

int main(){
    //FILE* file;
    //file = fopen("entrada.txt", "r");

    ifstream arq;
    arq.open("entrada.txt");

    if(arq.fail()) {
        cout << "Erro na leitura do arquivo." << endl;
        exit (1);
    }

    int memInst[128][32];
    for(int i = 0; i < 128; i++) 
        memInst[i][0] = -1;

    int k = 0;
    string auxStr;
    while(arq.good() && k < 128){
        getline(arq, auxStr, '\n');
        for (int j = 0; j < 32; j++){
            if(auxStr[j] == '0')
                memInst[k][j] = 0;
            if(auxStr[j] == '1')
                memInst[k][j] = 1;
        }
        k++;
    }
        

    if(k == 128){
        cout << "Atingiu o limite da memoria de instrucoes." << endl;
        cout << "Deseja continuar a execucao com as 128 primeiras instrucoes? (y/n) ";
    }

    k = 0;
    while(memInst[k][0] != -1){


        // IF_ID
        IF_ID instruction_fetched;
        instruction_fetched.novaInstrucao(memInst[k], k*4);
        cout << endl;
        //banco registradores

        //ID_EX
        //Alum
        //shif
        //ad pc+4 + j


        //
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        k++;
    }
    

}