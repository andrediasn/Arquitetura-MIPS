#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <bitset>
#include "MemInstrucoes.h"


using namespace std;

int main(){
    ifstream arqIn;
    arqIn.open("entrada.txt");

    if(arqIn.fail()) {
        cout << "Erro na leitura do arquivo." << endl;
        exit (1);
    }

    //int memInst[128];
    int i = 0;
    string aux;
    while(arqIn.good() && i < 128){
        getline(arqIn, aux, '\n');
        MemInstrucoes memInstrucoes;
        bitset<32> bit(aux);
        memInstrucoes.novoPC(i, aux);
        i++;
    }
    if(i == 128){
        cout << "Atingiu o limite da memoria de instrucoes." << endl;
        cout << "Deseja continuar a execucao com as 128 primeiras instrucoes? (y/n) ";
    }


}