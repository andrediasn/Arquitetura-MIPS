Controle::Controle(int vet[8]){
    for(int i = 0; i < 8; i++){
        entrada[i] = vet[i] ;
    }

}

Controle::~Controle() { }

Controle::setAluOp() {
    if(entrada[6] == 0 && entrada[7] == 0){
        aluOp[0] = 0;
        aluOp[1] = 0;
    }
    if(entrada[6] == 1 && entrada[7] == 0){
        aluOp[0] = 0;
        aluOp[1] = 1;
    }
    if(entrada[7] == 1){
        aluOp[0] = 1;
        aluOp[1] = 0;
    }

}

Controle::setFunctField() {
    for(int i = 0 ; i < 6 ; i++){
        functField[i] = entrada[i]
    }
}

Controle::setSaida() {
    if(aluOp[0] == 0 && aluOp[1] == 0){                      // lw ou sw

    }                
}