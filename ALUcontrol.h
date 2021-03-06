#ifndef ALUCONTROL_H_INCLUDED                                       
#define ALUCONTROL_H_INCLUDED

using namespace std;

class ALUcontrol
{
    private:

        int Operation[4];       // é a saida da ALU
        int functField[6];      // Recebe da IF_ID
        bool ALUOp1;            // Recebe da IF_ID
        bool ALUOp0;            // Recebe da IF_ID
        

    public:

        ALUcontrol() {
            ofstream arq("saida.txt", ios::app);
            cout << " -> set ALUcontrol" << endl;
            arq << " -> set ALUcontrol" << endl;
            arq.close();
        };
        ~ALUcontrol() {};

        int* getOperation(int funct[],bool Op1,bool Op0){
            for(int i = 0; i < 6; i++)
                this->functField[i] = funct[i];
            ALUOp1 = Op1;
            ALUOp0 = Op0;

            if(ALUOp0 == 0 && ALUOp1 == 0){   // lw ou sw
                this->Operation[0] = 0;
                this->Operation[1] = 0;
                this->Operation[2] = 1;
                this->Operation[3] = 0;
            }
            else if(ALUOp0 == 1){             // beq
                this->Operation[0] = 0;
                this->Operation[1] = 1;
                this->Operation[2] = 1;
                this->Operation[3] = 0;
            }
            else {                             // R-Type
                if(functField[2] == 1 && functField[3] == 0 && functField[4] == 1 && functField[5] == 0){      // set on less than
                    this->Operation[0] = 0;
                    this->Operation[1] = 1;
                    this->Operation[2] = 1;
                    this->Operation[3] = 1;
                }
                else if(functField[2] == 0 && functField[3] == 1 && functField[4] == 0 && functField[5] == 1){   // OR
                    this->Operation[0] = 0;
                    this->Operation[1] = 0;
                    this->Operation[2] = 0;
                    this->Operation[3] = 1;
                }
                else if(functField[2] == 0 && functField[3] == 1 && functField[4] == 0 && functField[5] == 0){   // AND
                    this->Operation[0] = 0; 
                    this->Operation[1] = 0;
                    this->Operation[2] = 0;
                    this->Operation[3] = 0;
                }
                else if(functField[2] == 0 && functField[3] == 0 && functField[4] == 1 && functField[5] == 0) {   // subtract
                    this->Operation[0] = 0;
                    this->Operation[1] = 1;
                    this->Operation[2] = 1;
                    this->Operation[3] = 0;
                }
                else if(functField [0] == 1 && functField[2] == 0 && functField[3] == 0 && functField[4] == 0 && functField[5] == 0) {   // ADD
                    this->Operation[0] = 0;
                    this->Operation[1] = 0;
                    this->Operation[2] = 1;
                    this->Operation[3] = 0;
                }else if(functField [0] == 0 && functField[2] == 0 && functField[3] == 0 && functField[4] == 0 && functField[5] == 0){                                                                   // sll
                    this->Operation[0] = 1;
                    this->Operation[1] = 0;
                    this->Operation[2] = 0;
                    this->Operation[3] = 0;
                }
                
            }
            return this->Operation;                
        } 

};
#endif // ALUCONTROL_H_INCLUDED