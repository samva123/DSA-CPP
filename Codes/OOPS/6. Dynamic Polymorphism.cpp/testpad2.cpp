#include <iostream>
using namespace std;

class Vegetable {
public:
    virtual void two() {
        cout << "V 2" << endl;
    }
};

class Mineral : public Vegetable {
public:
    virtual void one() {
        cout << "M 1" << endl;
    }
    virtual void two() {
        cout << "M 2" << endl;
    }
};

class Animal : public Mineral {
public:
    virtual void one() {
        cout << "A 1" << endl;
        two();
    }
    virtual void three() {
        cout << "A 3" << endl;
    }
};

class Computer : public Animal {
public:
    virtual void two() {
        cout << "C 2" << endl;
        Mineral::two();
    }
    virtual void three() {
        cout << "C 3" << endl;
    }
};

int main() {
    // Example usage of classes
   Vegetable* var1 = new Computer();
Mineral*  var2 = new Animal();
Vegetable* var3 = new Vegetable();
Animal*   var4 = new Computer();
 var2->one();
    return 0;
}
