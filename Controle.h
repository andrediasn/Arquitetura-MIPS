#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
class Controle
{
    public:
    Controle(int vet[8]);
    ~Controle();
    
    
    private:
    int aluOp[2];
    int aluSaida[4];
    int entrada[8];
    int functField[6];
    void setAluOp();
    void setSaida();
    void setFunctField();
};
#endif // CONTROLE_H_INCLUDED