#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "IF_ID.h"
#include "ID_EX.h"


using namespace std;

int main(){
    //FILE* file;
    //file = fopen("entrada.txt", "r");

    ifstream arq;
    arq.open("Entradas/entrada.txt");

    if(arq.fail()) {
        cout << "Erro na leitura do arquivo." << endl;
        exit (1);
    }

    int memInst[128][32];  // Matriz da Memoria de Instrucoes
    for(int i = 0; i < 128; i++) 
        memInst[i][0] = -1; // Inicializando primeira coluna de cada linha com -1 para indicar que esta sem instrucao.


    // ============= Etapa 1: IF - Instruction Fetch ======================================== // 

    // Lendo instrucoes de entrada e salvando na Memoria de Instrucoes
    int k = 0; // Representa a linha da matriz, PC = k * 4
    string auxStr; // string aux para receber linha da entrada
    while(arq.good() && k < 128){ // Enquanto nao chegou o fim do arquivo de entrada e nao foi atingido o limite de 128 instrucoes.
        getline(arq, auxStr, '\n');
        cout<< k << " - " << auxStr.size()<<endl;
        /*if(auxStr.size() != 32){
            int opc;
                do{ // Loop para resolver o erro.
                    cout << " Erro: a linha " << (k+1) << " possui quantidade de caracteres diferente de 32." << endl;
                    cout << " - Digite 1 para encerrar." << endl;
                    cout << " - Digite 2 para prosseguir e ler a proxima linha de instrucoes." << endl;
                    cout << "Indique o que deseja fazer: ";
                    cin >> opc;
                    if (opc == 1)
                        exit (1); // Encerra programa
                    else if( opc != 2)
                        cout << " Erro: Opcao invalida!!" << endl;
                }while(opc != 2); // Interrome for. Prossegue para proxima linha do arqivo de entrada
        }*/
        //else{
            for (int j = 0; j < 32; j++){  // Matriz recebe bit a bit
                if(auxStr[j] == '0')
                    memInst[k][j] = 0;
                else
                    memInst[k][j] = 1;
            }
        //}
        k++;
    }
    
    cout << endl;
    for (int i = 0; i < 32; i++) 
       cout << memInst[0][i];
     
        
    if(k == 128){
        int opc;
        do{
            cout << "Erro: Atingiu o limite de 128 da Memoria de Instrucoes." << endl;
            cout << " - Digite 1 para encerrar." << endl;
            cout << " - Digite 2 para prosseguir execucao com as 128 primeiras instrucoes.";
            if (opc == 1)
                        exit (1); // Encerra programa
            else if(opc != 2)
                        cout << " Erro: Opcao invalida!!" << endl;
        }while(opc != 2); //Prossegue para proxima linha do arqivo de entrada
    }

    k = 0;
    //while(memInst[k][0] != -1){

        // ============= Etapa 2: ID - Instruction decode / Register file read ============= // 

        int PC = k * 4;
        IF_ID *etapa2 = new IF_ID(memInst[k], PC);
        //*etapa2.start();


        // ============= Etapa 3: EX - Execute / Address calculation ======================= // 

        //ID_EX *etapa3;
        //etapa3->get();

        // Etapa 3 do Pipiline:

        // Etapa 4 do Pipiline:

        // Etapa 5 do Pipiline:
        // Aqui o valor do pc sera retornado.
        k = PC / 4;
         
        
    //}

    // instruction [31][30][29]
}