#ifndef ALU_H_INCLUDED                                        // AINDA NAO MEXIDO, APENAS COPIADO DO CONTROLE.H
#define ALU_H_INCLUDED
class ALU
{
    private:
        int entrada[8]; // Recebe da IF_ID
        int aluOp[2];
        int aluSaida[4];
        int functField[6];
        

    public:
        ALU();
        ~ALU();

        void attALU(int vet[]);
        int* getAluOp();
        int* getSaida();
        int* getFunctField();
   
};
#endif // ALU_H_INCLUDED