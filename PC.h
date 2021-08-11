#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

typedef struct pc{
    int id;
};


class PC {
    private:

    public:
    PC();
    ~PC();

    int getID() { return this.id};








    
};
#endif // PC_H_INCLUDED