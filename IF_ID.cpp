#include "IF_ID.h"


IF_ID::IF_ID(int memInst[], int PC){    // =============   Escreve em IF_ID ============= //
    ofstream arq("saida.txt", ios::app);
    cout << " -> Write IF_ID" << endl;
    arq << " -> Write IF_ID" << endl; 
    arq.close();
    this->PC = PC;
    for(int i = 0; i < 6; i++)
        this->controle[5-i] = memInst[i];  // Ex: i=0 -> controle[5] = memInst[0] | i=1 -> controle[4] = memInst[1]
        //[i] = [i] se for padronizado

    for(int i = 0; i < 5; i++)
        this->readRegister1[i] =  memInst[i+6]; // Ex: readRegister1[0] =  memInst[6] | readRegister1[4] =  memInst[10]

    for(int i = 0; i < 5; i++)
        this->readRegister2[i] =  memInst[i+11]; // Ex: readRegister2[0] =  memInst[11] | readRegister2[4] =  memInst[15]

    for(int i = 0; i < 16; i++)
        this->instruction_15_0[i] = memInst[i+16]; // Ex: instruction_15_0[0] = memInst[16] | instruction_15_0[15] = memInst[31]

    for(int i = 0; i < 5; i++) 
        this->instruction_20_16[i] = memInst[i+11]; // Ex: instruction_20_16[0] = memInst[11] | instruction_20_16[4] = memInst[15]
    
    for(int i = 0; i < 5; i++) 
        this->instruction_15_11[i] = memInst[i+16]; // Ex: instruction_15_11[0] = memInst[16] | instruction_15_11[4] = memInst[20]

    for(int i= 0; i < 26; i++)
        this->jump_25_0[i] = memInst[i+6];

    for(int i = 0; i < 6; i++)                                               // CONFIRMAR SE ESTA PEGANDO O CAMPO FUNCT
        this->instruction_5_0[i] = memInst[i+26];
    
    for(int i = 0; i < 5; i++)                                               // Confirmar se esta pegando o campo shamt
        this->instruction_10_6[i] = memInst[i+21];
}

IF_ID::~IF_ID(){}

        // ================= INICIA ETAPA 2 ================ //

ID_EX* IF_ID::start(int **registers){      
        
        // ================   Lendo de IF_ID ===================== //
    ofstream arq("saida.txt", ios::app);
    cout << " -> Read IF_ID" << endl;
    arq << " -> Read IF_ID" << endl;
    arq.close();
    
    Controle control;
    control.attControle(this->controle, this->instruction_5_0); // Bits enviados ao Controle Principal: 31-26           (e campo funct)
    
    BancoRegistradores reg;
    reg.setReadData(this->readRegister1, this->readRegister2, registers); // Bits enviados ao Banco de Registradores: 25-21 e 20-16
    
    OpLogicos op;
    op.extensorSinal(this->instruction_15_0); // Bits enviados ao Extensor de Sinal: 15-0
    op.shiftLeft2(this->jump_25_0); // endere??o de jump enviados para deslocamento;

        // ===============   Escreve em ID_EX ==================  //
    ID_EX *idex = new ID_EX(this->PC, this->instruction_15_11, this->instruction_20_16,this->instruction_10_6, control, reg, op);

    return idex; // Retorna para main
}

