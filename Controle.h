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
        void setAllSaida();         // seta todos os valores
        bool getRegDst();
        bool getALUSrc();
        bool getMemtoReg();
        bool getRegWrite();
        bool getMemRead();
        bool getMemWrite();
        bool getBranch();
        bool getALUOp0();
        bool getALUOp1();
                                
        
};
#endif // CONTROLE_H_INCLUDED