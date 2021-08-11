#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <bitset>


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
    int i = 0;
    string auxStr;
    while(arq.good() && i < 128){
        getline(arq, auxStr, '\n');
        for (int j = 0; j < 32; j++){
            if(auxStr[j] == '0')
                memInst[i][j] = 0;
            if(auxStr[j] == '1')
                memInst[i][j] = 1;
            cout << memInst[i][j];
        }
        i++;
    }

    if(i == 128){
        cout << "Atingiu o limite da memoria de instrucoes." << endl;
        cout << "Deseja continuar a execucao com as 128 primeiras instrucoes? (y/n) ";
    }

    

}