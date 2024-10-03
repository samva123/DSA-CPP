#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bird
{
    private :
    string gf ;
    
    protected:
    string wife ;
public:
    int age, weight;
    int nol;
    string color;

    Bird(){
        cout << "deafult cor" << endl;
    }

    Bird(string gf , int age ){
        this -> gf = gf ;
        this -> age = age ;
    }

    void eat()
    {
        cout << "Bird is Eating" << endl;
    }

    void fly()
    {
        cout << "Bird is Flying" << endl;
    }
    string getgf(){
        return this->gf ;
    }
};

class Sparrow : protected Bird
{
public:
Sparrow(){

}


    Sparrow(int age, int weight, string color, int nol , string wife)
    {
        this->age = age;
        this->weight = weight;
        this->color = color;
        this->nol = nol;
       //this -> gf = gf ;
       this -> wife = wife;
       cout << "i am parameterized" << endl;
    }

    int getNol()
    {
        return this->nol;
    }

    void grassing()
    {
        cout << "Sparrow is grassing" << endl;
    }

    string getwife(){
        return this->wife ;
    }

    int getnol(){
        return this->nol;
    }
    // string getgf(){
    //     return this-> gf;
    // }
    
};

class Peigon : public Sparrow
{
public:
    Peigon(int age , int weight , string wife){
        this -> age = age;
        this -> weight = weight;
        this -> wife = wife;

    }
    void guttering()
    {
        cout << "Peigon is guttering" << endl;
    }
    string getwife(){
        return this->wife ;
    }
};

class Parrot : protected Bird
{
    
public:

    // string getwife(){
    //     return this->wife;
    // }
    void speaking()
    {
        cout << "Parrot is speaking" << endl;
    }
    //void print()
};
class yashasvi : public Parrot{

    string getwife(){
        return this->wife;
    } 

};
int main()
{
  //  Sparrow s(1, 1, "brown", 2 , "janu");
   // s.grassing();
    //cout << s.color << endl;
    // s.eat();
    // s.grassing();
    // Bird golu("chutki" , 2);
    // cout << golu.getgf() << endl;
    // cout << golu.age << endl;;

    Sparrow s(1,2,"brown" ,3 , "hema");
    //s.age;
    cout << s.getwife();

    Peigon p(2,3,"hello");
    cout << p.getwife();
    
   // cout << golu.gf ; 


    // Peigon p;
    // p.eat();
    // p.guttering();
    //Parrot p ;
     // p.age ;
    return 0;
}