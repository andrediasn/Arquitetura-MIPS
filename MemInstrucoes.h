#ifndef MEMINSTRUCOES_H
#define MEMINSTRUCOES_H
#include <string>
#include <vector>  
#include "PC.h" 


class MemInstrucoes
{
public:
    MemInstrucoes();
    virtual ~MemInstrucoes();

    void novoPC(int i, string instrucao); //cria um novo no e armazena as informacoes do artista
    void imprimeIds(); 
    void NovaLista(string arq1);
    void deletaultimo();


private:
    int n;
    PC *primeiro;
    PC *ultimo;
    
};

#endif // MEMINSTRUCOES_H