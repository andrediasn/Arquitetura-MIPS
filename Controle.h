class Controle
{
    public:
    Controle(int vet[8]);
    ~Controle();
    void setAluOp();
    void setSaida();
    void setFunctField();
    
    private:
    int aluOp[2];
    int aluSaida[4];
    int entrada[8];
    int functField[6];
};