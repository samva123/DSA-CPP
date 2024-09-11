#include <iostream>

using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y);
    }

    void print() const
    {
        cout << "1 : " << x << endl;
        cout << "2 : " << y << endl;
        cout << "3 : " << *y << endl;
    }

    ~abc(){
        delete y;
    }
};

int main()
{
    // abc a(1, 2);
    // cout << "print a 1 " << endl;
    // a.print();

    // abc b = a;
    // cout << "print b" << endl;
    // b.print();

    // *b.y = 20;
    // b.x = 20 ;
    // cout << "print b again " << endl;
    // b.print();

    // cout << "print a 1 again " << endl;
    // a.print();

    abc *a = new abc(1,2);
    abc b = *a;
    delete a;
    b.print();
    return 0;

    
}
