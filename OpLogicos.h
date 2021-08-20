#ifndef OPLOGICOS_H_INCLUDED
#define OPLOGICOS_H_INCLUDED
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;
using std::string;
class OpLogicos{
    private:
        int vetExtSinal [32];
        int vetJump [32];

    public:
        OpLogicos(){}
        ~OpLogicos(){}

        void extensorSinal(int vetIn[]){
            cout << " -> Sign-extend" << endl; 
            if(vetIn[0]==0){
                for(int i=0;i<16;i++)
                    this->vetExtSinal[i] = 0;
                for(int i=16;i<32;i++)  
                    this->vetExtSinal[i] = vetIn[i-16];
            }
            else{
                for(int i=0;i<16;i++)
                    this->vetExtSinal[i] = 1;
                for(int i=16;i<32;i++)  
                    this->vetExtSinal[i] = vetIn[i-16];
            }
        }

        int* getExtensorSinal(){
            return this->vetExtSinal;
        }

        int* shiftLeft(int vet[], int bits, int result[]){
            cout << " -> Shift Left 2" << endl; 
            for(int i=0;i<(32-bits); i++)
                result[i] = vet[i+bits];
            for(int i=(32-bits);i<32;i++)
                result[i] = 0;
            return result; 
        }

        void shiftLeft2(int vet[]){ // para o jump
            cout << " -> Shift Left 2" << endl; 
            for(int i=0;i<4;i++) // Soma mais significativos de PC
                this->vetJump[i] = 0;
            for(int i=4;i<30; i++) // Copia Jump
                this->vetJump[i] = vet[i-4];
            for(int i=30;i<32;i++) // acrescenta 2 bits no menos significativo
                this->vetJump[i] = 0;
        }

        int* getVetJump() { return this->vetJump;}


        int ADD(int PC, int jump[]){
            cout << " -> ADD" << endl; 
            int desvio = 0;
            for(int i = 15; i < 32; i++) // bit17 pois o bit16 é o indicador de sinal
                desvio += jump[i] * pow(2,31-i);
            return (PC + desvio);
        }

        int addPC(int PC){
            cout << " -> ADD" << endl;
            return (PC+4);
        }

        int* mutiplexador(int vet1[], int vet2[], bool control){
            cout << " -> MUX" << endl; 
            if(control)
                return vet2;
            return vet1;
        }
        
        int* mutiplexador2(int ALUresult[], int readData[], int PCbin[], bool MemToReg[]){
            cout << " -> MUX" << endl;
            if(MemToReg[0] == 1)
                return readData;
            if(MemToReg[1] == 1)
                return PCbin;
            return ALUresult;
        }

         int* mutiplexador3(int aux0[], int aux1[], int aux2[], bool control[]){
            cout << " -> MUX" << endl;
            if(control[1] == 0) // alu // 20-16
                return aux0;
            if(control[0] == 1) // pc //  ra
                return aux1;
            return aux2; // readData //  15-11
        }



        int muxPC(int aux0, int aux1, bool control){
            cout << " -> MUX" << endl;
            if(control)
                return aux1;
            return aux0;
        }

        int muxPC(int pc, int jr, int jump,  bool control[]){
            cout << " -> MUX" << endl;
            if(control[1] == 0)
                return pc;
            else if(control[0] == 1)
                return jr;            
            return jump;
        }


        int AND(bool branch, bool zeroAlu){
            cout << " -> AND" << endl;
            if(branch && zeroAlu)
                return true;
            return false;
        }

        int* toBinary(int n,int vet[]){ //usar no jal
            string r;
            while (n != 0){
                r += ( n % 2 == 0 ? "0" : "1" );
                n /= 2;
            } 
            int tam = r.size();
            tam = 32 - tam;
            for(int i = 0; i < tam; i++)
                vet[i] = 0;
            int j = r.size()-1;
            for(int i = tam; i < 32; i++){
                if(r[j] == '0')
                    vet[i] = 0;
                else
                    vet[i] = 1;
                j--;
            }
            return vet;
        }     
        
};


#endif // OPLOGICOS_H_INCLUDED