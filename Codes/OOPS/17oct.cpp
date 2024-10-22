#include <iostream>
using namespace std;

class Parent{

    public :

    void show(){
        cout << "Parent" << endl;
    }



};


class child1 : public Parent{

    void show(){
        cout << "child" << endl;
    }

};


int main(){


    
    return 0;
}