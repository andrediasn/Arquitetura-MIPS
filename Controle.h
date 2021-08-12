#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
class Controle
{
    private:
        int Op[6]; // Recebe da IF_ID
        bool RegDst;
        bool ALUSrc;
        bool MemtoReg;
        bool RegWrite;
        bool MemRead;
        bool MemWrite;
        bool Branch;
        bool ALUOp0;
        bool ALUOp1;
        
    public:
        Controle();
        ~Controle();

        void attControle(int vet[]);
        bool getAllSaida();                        // enviando tudo 
        
};
#endif // CONTROLE_H_INCLUDED