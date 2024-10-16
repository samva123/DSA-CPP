#include <iostream>
using namespace std;


class Rectangle{
    

    public :

    int len ;
    int bre; 
    
    Rectangle(int len , int  bre){
        this->len = len;
        this->bre = bre;
    }
};

int main(){
    Rectangle one(1,2);
    cout << one.len; 
    

}

