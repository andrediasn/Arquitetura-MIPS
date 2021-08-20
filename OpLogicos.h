#ifndef OPLOGICOS_H_INCLUDED
#define OPLOGICOS_H_INCLUDED
#include <iostream>
#include <math.h>

using namespace std;
class OpLogicos{
    private:
        int vetExtSinal [32];
        int vetJump [32];

    public:
        OpLogicos(){}
        ~OpLogicos(){}

        void extensorSinal(int vetIn[]){
            ofstream arq("saida.txt", ios::app);
            cout << " -> Sign-extend" << endl; 
            arq << " -> Sign-extend" << endl; 
            arq.close();
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
            ofstream arq("saida.txt", ios::app);
            cout << " -> Shift Left 2" << endl;
            arq << " -> Shift Left 2" << endl; 
            arq.close();
            for(int i=0;i<(32-bits); i++)
                result[i] = vet[i+bits];
            for(int i=(32-bits);i<32;i++)
                result[i] = 0;
            return result; 
        }

        void shiftLeft2(int vet[]){ // para o jump
            ofstream arq("saida.txt", ios::app);
            cout << " -> Shift Left 2" << endl;
            arq << " -> Shift Left 2" << endl;
            arq.close(); 
            for(int i=0;i<4;i++) // Soma mais significativos de PC
                this->vetJump[i] = 0;
            for(int i=4;i<30; i++) // Copia Jump
                this->vetJump[i] = vet[i-4];
            for(int i=30;i<32;i++) // acrescenta 2 bits no menos significativo
                this->vetJump[i] = 0;
        }

        int* getVetJump() { return this->vetJump;}


        int ADD(int PC, int jump[]){
            ofstream arq("saida.txt", ios::app);
            cout << " -> ADD" << endl;
            arq << " -> ADD"  << endl;
            arq.close();
            int desvio = 0;
            for(int i = 15; i < 32; i++) // bit17 pois o bit16 é o indicador de sinal
                desvio += jump[i] * pow(2,31-i);
            return (PC + desvio);
        }

        int addPC(int PC){
            ofstream arq("saida.txt", ios::app);
            cout << " -> ADD" << endl;
            arq << " -> ADD"  << endl;
            arq.close();
            return (PC+4);
        }

        int* mutiplexador(int vet1[], int vet2[], bool control){
            ofstream arq("saida.txt", ios::app);
            cout << " -> MUX" << endl;
            arq << " -> MUX" << endl; 
            arq.close();
            if(control)
                return vet2;
            return vet1;
        }
        
        int* mutiplexador2(int ALUresult[], int readData[], int PCbin[], bool MemToReg[]){
            ofstream arq("saida.txt", ios::app);
            cout << " -> MUX" << endl;
            arq << " -> MUX" << endl; 
            arq.close();
            if(MemToReg[0] == 1)
                return readData;
            if(MemToReg[1] == 1)
                return PCbin;
            return ALUresult;
        }

         int* mutiplexador3(int aux0[], int aux1[], int aux2[], bool control[]){
            ofstream arq("saida.txt", ios::app);
            cout << " -> MUX" << endl;
            arq << " -> MUX" << endl; 
            arq.close();
            if(control[1] == 0) // alu // 20-16
                return aux0;
            if(control[0] == 1) // pc //  ra
                return aux1;
            return aux2; // readData //  15-11
        }



        int muxPC(int aux0, int aux1, bool control){
            ofstream arq("saida.txt", ios::app);
            cout << " -> MUX" << endl;
            arq << " -> MUX" << endl; 
            arq.close();
            if(control)
                return aux1;
            return aux0;
        }

        int muxPC(int pc, int jr, int jump,  bool control[]){
            ofstream arq("saida.txt", ios::app);
            cout << " -> MUX" << endl;
            arq << " -> MUX" << endl; 
            arq.close();
            if(control[1] == 0)
                return pc;
            else if(control[0] == 1)
                return jr;            
            return jump;
        }


        bool AND(bool branch, bool zeroAlu){
            ofstream arq("saida.txt", ios::app);
            cout << " -> AND" << endl;
            arq << " -> AND" << endl;
            arq.close();
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
        bool OR( bool zeroPCSrc, bool zeroBne) {
            ofstream arq("saida.txt", ios::app);
            cout << " -> OR" << endl;
            arq << " -> OR" << endl;
            arq.close();
            if(zeroBne == 1 || zeroPCSrc == 1)
                return true;
            else
                return false;
        }     
        
};


#endif // OPLOGICOS_H_INCLUDED