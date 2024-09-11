#include <iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout << "constructor hai" << endl;
    }
    virtual ~Base(){
        cout << "destructor hai " << endl;
    }

};

class Derived : public Base{
    public : 
    Derived(){
        cout << "derived ka constructor hai" << endl;
    }

    ~Derived(){
        cout << "derived ka destructor hai " << endl;
    }

};

int main(){

    Base *b = new Derived();
    
    delete b ;
    return 0;

}