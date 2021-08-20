#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
#include <iostream>

class Controle
{
    private:
    
        int Op[6]; // Recebe da IF_ID
        bool RegDst;
        bool RegDst2;
        bool ALUSrc;
        bool MemToReg;
        bool MemToReg2;
        bool RegWrite;
        bool MemRead;
        bool MemWrite;
        bool Branch;
        bool Jump;
        bool ALUOp0;
        bool ALUOp1;
        
    public:

        Controle(){}
        ~Controle(){}

        void attControle(int vet[]){
            std::cout << " -> set Control" << std::endl;
            for(int i = 0; i < 6; i++)
                this->Op[i] = vet[i];
            setAllSaida();
        }

        void setAllSaida(){
            if(Op[5] == 1 && Op[3] == 0){  // é uma operação LW
            this->RegDst = 0;
            this->ALUSrc = 1;
            this->MemToReg = 1;
            this->RegWrite = 1;
            this->MemRead = 1;
            this->MemWrite = 0;
            this->Branch = 0;
            this->ALUOp1 = 0;
            this->ALUOp0 = 0;
            }else if(Op[5] == 1 && Op[3] == 1){   // é uma operação SW
                this->ALUSrc = 1;
                this->RegWrite = 0;
                this->MemRead = 0;
                this->MemWrite = 1;
                this->Branch = 0;
                this->ALUOp1 = 0;
                this->ALUOp0 = 0;
            }else if (Op[5] == 0 && Op[3] == 1){   // ADDI
                this->RegDst = 0;
                this->ALUSrc = 1;
                this->MemToReg = 0;
                this->RegWrite = 1;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->Branch = 0;
                this->ALUOp1 = 0;   
                this->ALUOp0 = 0;   
            }else if (Op[2] == 1) {   // é uma operaçao BEQ
                this->ALUSrc = 0;
                this->RegWrite = 0;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->Branch = 1;
                this->ALUOp1 = 0;
                this->ALUOp0 = 1;
            }else if(Op[1] == 1 && Op[0] == 0){            // JUMP
                this->Jump = 1;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->RegWrite = 0;
            }else if(Op[1] == 1 && Op[0] == 1){                  // JAL - Jump and Link  (incremento de regdst e memtoreg)
                this->Jump = 1;
                this->RegWrite = 1;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->MemToReg = 0;
                this->MemToReg2 = 1;
                this->RegDst = 0;
                this->RegDst2 = 1;
            }else{                   // é uma operaçao tipo R                  (Jr)
                this->RegDst = 1;
                this->ALUSrc = 0;
                this->MemToReg = 0;
                this->RegWrite = 1;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->Branch = 0;
                this->ALUOp1 = 1;
                this->ALUOp0 = 0;
            }
        }


        bool getRegDst() {return this->RegDst;}
        bool getALUSrc() {return this->ALUSrc;}
        bool getMemToReg() {return this->MemToReg;}
        bool getRegWrite() {return this->RegWrite;}
        bool getMemRead() {return this->MemRead;}
        bool getMemWrite() {return this->MemWrite;}
        bool getBranch() {return this->Branch;}
        bool getJump() {return this->Jump;}
        bool getALUOp1() {return this->ALUOp1;}
        bool getALUOp0() {return this->ALUOp0;}
                                
        
};
#endif // CONTROLE_H_INCLUDED