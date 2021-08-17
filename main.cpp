#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "IF_ID.h"  /// Lembrar de rever os includes .h em cadeia

using namespace std;

void wait(int etapa){
    cout << " -> Pressione enter para iniciar etapa " << etapa << endl;
    string aux;
    cin >> aux;
}

void pipeline(int** memInst, int** dataMem, int** registers, int opcao){

    int id = 0;
    int clock = 0;
    while(memInst[id][0] != -1){ // Rever essa verificacao

        int PC = id * 4;
        IF_ID *etapa2 = new IF_ID(memInst[id], PC);  // Etapa 1: IF - Instruction Fetch  // 
        if(opcao == 1) { wait(1);}

        ID_EX *etapa3 = etapa2->start(registers);  // Etapa 2: ID - Instruction decode / Register file read // 
        if(opcao == 1) { wait(2);}

        EX_MEM *etapa4 = etapa3->start(); // Etapa 3: EX - Execute / Address calculation //
        if(opcao == 1) { wait(3);} 

        MEM_WB *etapa5 = etapa4->start(dataMem); // Etapa 4: MEM - Memory access  // 
        if(opcao == 1) { wait(4);} 

        PC = etapa5->start(registers);  // Etapa 5: WB - Write Back // 
        if(opcao == 1) { wait(5);} 

        if( PC%4 == 0 ) // Verifica se PC é multiplo de 4
            id = PC / 4; // Atualiza posicao da proxima instrucao
        else {
            cout << "Endereco de PC = " << PC << "invalido" << endl;
            cout << "Interrompendo execucao" << endl;
            break;
        }
        clock++;
    }
}

void leituraInst(int **memInst, int opcao){
    if(opcao == 1){
        bool erro = true;
        do{
            string dir; // Recebe nome do arquivo
            cout << "Digite o nome do arquivo: ";
            cin >> dir;
            ifstream arq;
            arq.open(dir);

            if(arq.fail())  // Se arquivo nao foi encontrado
                cout << "Erro na leitura do arquivo." << endl;
            else{
                // Lendo instrucoes de entrada e salvando na Memoria de Instrucoes
                int i = 0; // Representa a linha da matriz, PC = k * 4
                string aux; // string aux para receber linha da entrada
                while(arq.good() && i < 128){ // Enquanto nao chegou o fim do arquivo de entrada e nao foi atingido o limite de 128 instrucoes.
                    getline(arq, aux, '\n');
                        for (int j = 0; j < 32; j++){  // Matriz recebe bit a bit
                            if(aux[j] == '0')
                                memInst[i][j] = 0;
                            else
                                memInst[i][j] = 1;
                        }
                    i++;
                }
                erro = false;
                arq.close();
            }
        }while(erro);
    }
    else{
        cout << "Escreva uma linha de 32 bits contendo as instrucoes referente as linhas a seguir: " << endl;
        cout << "(Para indicar que encerrou, digite o numero 2)" << endl;
        int i = 0;
        while(i < 128){
            cout << i << ": " << endl;
            string aux;
            cin >> aux;
            if (aux[0] == 2){
                cout << "Leitura de instrucoes concluidas." << endl;
                break;
            }
            else if(aux.size() == 32){
                for (int j = 0; j < 32; j++){  // Matriz recebe bit a bit
                    if(aux[j] == '0')
                        memInst[i][j] = 0;
                    else if (aux[j] == '1')
                        memInst[i][j] = 1;
                    else{
                        cout << "Deve ser inserido apenas 0 ou 1." << endl;
                        i--;
                        break;
                    }
                }
                i++;
            }
            else
                cout << "Devem ser inseridos 32 bits." << endl;
        }
    }
}

void reset(int **dataMem, int **registers){
    dataMem = new int*[128];
    for(int i=0; i<128; i++)
        dataMem[i] = new int[32];

    registers = new int*[32];
    for(int i=0; i<32; i++) 
        registers[i] = new int[32];
}

void menu (int **dataMem, int **registers, int **memInst){
    int opcao;
    do{ 
        cout << endl << " ---- " << endl;
        cout << "Indique o numero da opcao escolhida referente a inicializacao da Memoria de Instrucoes:" << endl;
        cout << " - [1] Para incerir o nome do arquivo para leitura." << endl;
        cout << " - [2] Para incerir instrucoes manualmente." << endl;
        cout << " - [3] Para reset dataMem e registers" << endl;
        cout << " - [0] Encerrar execucao do programa." << endl;
        cout << "Opcao escolhida: ";
        cin >> opcao;
        if(opcao == 1)
            leituraInst(memInst, opcao);      
        else if (opcao == 2)
            leituraInst(memInst, opcao);
        else if (opcao == 3)
            reset(dataMem, registers);
        else if (opcao != 0)
            cout << "Opcao " << opcao << "invalida." << endl << endl;
        if (opcao == 1 || opcao == 2){
            cout << "Indique o numero da opcao escolhida referente ao metodo de execucao:" << endl;
            cout << " - [1] Para modo etapa-a-etapa." << endl;
            cout << " - [2] Para modo direto." << endl;
            cout << " - [3] Para reset dataMem e registers" << endl;
            cout << " - [0] Encerrar execucao do programa." << endl;
            cout << "Opcao escolhida: ";
            cin >> opcao;
            if(opcao == 1)
                pipeline(memInst, dataMem, registers, opcao);      
            else if (opcao == 2)
                pipeline(memInst, dataMem, registers, opcao);
            else if (opcao == 3)
                reset(dataMem, registers);
            else if (opcao != 0)
                cout << "Opcao " << opcao << "invalida." << endl << endl;
        }
    }while(opcao != 0);
    exit(1);
}

void inicializaDados(int **data, int tam, string dir){ // Funcao usada para testes internos
    ifstream arq;
    arq.open(dir);
    if(arq.fail()){
        cout << "Erro na leitura de " << dir << endl;
        exit(1);
    }
    string lixo, bin;
    int l = 0;
    while(l < tam){
        getline(arq, lixo, '#');
        getline(arq, bin, '\n');
        for (int j = 0; j < 32; j++){  // Matriz recebe bit a bit
                if(bin[j] == '0')
                    data[l][j] = 0;
                else
                    data[l][j] = 1;
        }
        l++;
    }
}



int main(){
    // Criando Memoria de dados
    int **dataMem;                  
    dataMem = new int*[128];
    for(int i=0; i<128; i++)
        dataMem[i] = new int[32];
    inicializaDados(dataMem, 128, "Dados/dataMem.txt"); // Inicializa dataMem com nosso "lixo" para testes internos
    
    // Criando Banco de registradores
    int **registers;               
    registers = new int*[32];
    for(int i=0; i<32; i++) 
        registers[i] = new int[32];
    inicializaDados(registers, 32, "Dados/registers.txt"); // Inicializa dataMem com nosso "lixo" para testes internos
    

    int **memInst;  // Matriz da Memoria de Instruções
    memInst = new int*[128];
    for(int i = 0; i < 128; i++){ 
        memInst[i] = new int[32];
        memInst[i][0] = -1; // Inicializando primeira coluna de cada linha com -1 para indicar que esta sem instrucao.
    }
    menu(dataMem, registers, memInst);
   
}

void Imprimir(int clock, int PC, int **registers, int **instrucao) {
    cout << "Ciclo de clock atual: " << clock << endl;
    cout << "Valor do PC: " << PC << endl;
    cout << "Instrução: " << instrucao[clock] << endl;
    cout << "Valores armazenados em cada registrador: " << endl ;
    for(int i = 0; i < 32; i++) 
        cout << "Registrador " << i << " = " << registers[i] << endl;   
}