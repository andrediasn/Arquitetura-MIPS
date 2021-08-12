#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
class Controle
{
    private:
        int entrada[8]; // Recebe da IF_ID
        int aluOp[2];
        int aluSaida[4];
        int functField[6];

    public:
        Controle();
        ~Controle();

        void attControle(int vet[]);
        int* getAluOp();
        int* getSaida();
        int* getFunctField();
   
};
#endif // CONTROLE_H_INCLUDED