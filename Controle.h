#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
#include <iostream>

using namespace std;

class Controle
{
    private:
    
        int Op[6]; // Recebe da IF_ID
        int functField[6];  // Recebe de IF_ID
        bool RegDst[2];
        bool ALUSrc;
        bool MemToReg[2];
        bool RegWrite;
        bool MemRead;
        bool MemWrite;
        bool Branch;
        bool Jump[2];
        bool Bne;
        bool ALUOp0;
        bool ALUOp1;
        
    public:

        Controle(){}
        ~Controle(){}

        void attControle(int vet[], int funct[]){ 
            ofstream arq("saida.txt", ios::app);                
            cout << " -> set Control" << endl;
            arq << " -> set Control" << endl;
            arq.close();

            for(int i = 0; i < 6; i++){
                this->Op[i] = vet[i];
                this->functField[i] = funct[i];
            }
            setAllSaida();
        }

        void setAllSaida(){
            if(Op[5] == 1 && Op[3] == 0){  // é uma operação LW
            this->RegDst[1] = 0;
            this->ALUSrc = 1;
            this->MemToReg[0] = 0;
            this->MemToReg[1] = 1;
            this->RegWrite = 1;
            this->MemRead = 1;
            this->MemWrite = 0;
            this->Branch = 0;
            this->ALUOp1 = 0;
            this->ALUOp0 = 0;
            this->Jump[1] = 0;
            this->Bne = 0;
            }else if(Op[5] == 1 && Op[3] == 1){   // é uma operação SW
                this->ALUSrc = 1;
                this->RegWrite = 0;
                this->MemRead = 0;
                this->MemWrite = 1;
                this->Branch = 0;
                this->ALUOp1 = 0;
                this->ALUOp0 = 0;
                this->Jump[1] = 0;
                this->Bne = 0;
            }else if (Op[5] == 0 && Op[3] == 1){   // ADDI
                this->RegDst[1] = 0;
                this->ALUSrc = 1;
                this->MemToReg[1] = 0;
                this->RegWrite = 1;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->Branch = 0;
                this->ALUOp1 = 0;   
                this->ALUOp0 = 0; 
                this->Jump[1] = 0;
                this->Bne = 0;  
            }else if (Op[2] == 1 && Op[0] == 0) {   // é uma operaçao BEQ
                this->ALUSrc = 0;
                this->Bne = 0;
                this->RegWrite = 0;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->Branch = 1;
                this->ALUOp1 = 0;
                this->ALUOp0 = 1;
                this->Jump[1] = 0;
            }else if(Op[2] == 1 && Op[0] == 1){              // BNE
                this->Bne = 1;
                this->Branch = 0;
                this->ALUOp1 = 0;
                this->ALUOp0 = 1;
                this->MemWrite = 0;
                this->MemRead = 0;                  
                this->ALUSrc = 0;
                this->RegWrite = 0;
                this->Jump[1] = 0;
            }else if(Op[1] == 1 && Op[0] == 0){            // JUMP
                this->Jump[0] = 0;
                this->Jump[1] = 1;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->RegWrite = 0;
                this->Bne = 0;  
            }else if(Op[1] == 1 && Op[0] == 1){                  // JAL - Jump and Link
                this->Jump[0] = 0;
                this->Jump[1] = 1;
                this->RegWrite = 1;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->MemToReg[0] = 1;
                this->MemToReg[1] = 1;
                this->RegDst[0] = 1;
                this->RegDst[1] = 1;
                this->Bne = 0;  
            }else if(Op[1] == 0 && Op[0] == 0 && functField[2] == 1 && functField[3] == 0 && functField[4] == 0 && functField[5] == 0) {         //(Jr)
                this->Jump[0] = 1;
                this->Jump[1] = 1;
                this->MemWrite = 0;
                this->RegWrite = 0;
                this->Bne = 0;
            }else if(functField[0] == 0 && functField[1] == 0 && functField[2] == 0 && functField[3] == 0 && functField[4] == 0 && functField[5] == 0){  // sll
                this->ALUSrc = 0;
                this->RegWrite = 1;
                this->Branch = 0;
                this->Bne = 0;
                this->MemWrite = 0;
                this->MemRead = 0;
                this->MemToReg[1] = 0; 
                this->Jump[1] = 0;
                this->RegDst[0] = 0;
                this->RegDst[1] = 1;
                this->ALUOp0 = 0;
                this->ALUOp1 = 1;
            }else if (Op[5] == 0 && Op[4] == 0 && Op[3] == 0 && Op[2] == 0 && Op[1] == 0 && Op[0] == 0){                   // é uma operaçao tipo R                 
                this->Jump[1] = 0;
                this->RegDst[0] = 0;
                this->RegDst[1] = 1;
                this->ALUSrc = 0;
                this->MemToReg[1] = 0;
                this->RegWrite = 0;
                this->MemRead = 0;
                this->MemWrite = 0;
                this->Branch = 0;
                this->ALUOp1 = 1;
                this->ALUOp0 = 0;
                this->Bne = 0;
            }
        }


        bool* getRegDst() {return this->RegDst;}
        bool getALUSrc() {return this->ALUSrc;}
        bool* getMemToReg() {return this->MemToReg;}
        bool getRegWrite() {return this->RegWrite;}
        bool getMemRead() {return this->MemRead;}
        bool getMemWrite() {return this->MemWrite;}
        bool getBranch() {return this->Branch;}
        bool* getJump() {return this->Jump;}
        bool getBne() {return this->Bne;}
        bool getALUOp1() {return this->ALUOp1;}
        bool getALUOp0() {return this->ALUOp0;}
                       
        
};
#endif // CONTROLE_H_INCLUDED