#ifndef BANCOREGISTRADORES_H_INCLUDED
#define BANCOREGISTRADORES_H_INCLUDED

class BancoRegistradores{
    private:
        int registradoresData[32][32]; // Banco de registradores
        int readData1[32]; // Registrador que sera enviado para ID_EX 
        int readData2[32]; // Registrador que sera enviado para ID_EX

    public:
        BancoRegistradores();
        ~BancoRegistradores();

        void setReadData(int readRegister1[], int readRegister2[]); // Recebido de IF_ID
        int* getReadData1(); // Enviado para ID_EX
        int* getReadData2(); // Enviado para ID_EX


};

#endif //BANCOREGISTRADORES_H_INCLUDED