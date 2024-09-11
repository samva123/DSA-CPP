#include <iostream>
using namespace std;

class Abc
{
public:
    int x;
    int *y;
    int z ;

    // Abc()
    // {
    //     x = 0;
    //     y = new int(0);
    // }

    Abc( int _x , int _y){
        this -> x = _x;
        this -> y = new int(_y);
        
        *y = *y*10 ;
        // *y = _y; /////////// THIS IS WRONG WAYY
    }

    Abc (int _x , int _y , int _z ): x(_x) , y(new int(_y)) , z(_z) {
        *y = *y*10 ;
        x = x*10;
    }

    int getX() 
    {
        // x = 11 ;
        return x;
    }
     int getXX() 
    {
        x = 11 ;
        return x;
    }

      int getZ() 
    {
        // x = 11 ;
        return z;
    }
    int setX(int _val) 
    {
        // x = _val;
    }
    int setY(int _val)
    {
        *y = _val;
    }

    int getY() 
    {
        return *y;
    }
      int getYY() 
    {
        return *y;
    }


  
};
  void printABC (  Abc &a){
    a.setY(25);
        cout << a.getXX() <<"  " << a.getYY() << endl ;
    }

     void printABCD ( Abc &a){
       // a.setX(10);
        cout << a.getX() <<"  " << a.getY() << "  " <<  a.getZ() << endl ;
    }

int main()
{
   //// Abc a(1,2);
    // cout << a.getX() << endl;
    //     cout << a.getY() << endl;
  // printABC(a) ;


    Abc b (1,2,3);
    printABCD(b) ;
    return 0 ;
}