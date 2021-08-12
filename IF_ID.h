#ifndef IF_ID_H_INCLUDED
#define IF_ID_H_INCLUDED
#include "BancoRegistradores.h"

class IF_ID{
    private:

    public:
    IF_ID();
    ~IF_ID();
    void novaInstrucao(int memInst[], int PC);

};



#endif //IF_ID_H_INCLUDED