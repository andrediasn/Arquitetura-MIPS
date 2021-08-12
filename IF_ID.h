#ifndef IF_ID_H_INCLUDED
#define IF_ID_H_INCLUDED
class IF_ID{
    private:
    int PC;
    int controle[8]; // Para a unidade de controle
    int instruction_0_15[16]; // Para unidade operacional
    int instruction_11_15[5]; // Para ID_EX
    int instruction_16_20[5]; // Para ID_Ex
    int readRegister1[16]; // ver o valor de bits ta certo // Para banco de registradores
    int readRegister2[16]; // ver o valor de bits ta certo // Para banco de registradores

    void toID_EX();
    void toControle();
    void toBancoRegistradores();
    void toOpLogicos();
    
    public:
        IF_ID(int memInst[], int PC);
        ~IF_ID();
};

#endif //IF_ID_H_INCLUDED