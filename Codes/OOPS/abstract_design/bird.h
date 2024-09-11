#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

class Bird{
    public :
    virtual void eat() = 0; // this is called pure virtual function
    virtual void fly() = 0;

    // class that inherits this class
    // has to implement this pure virtual fns


};

class Sparrow : public Bird{
    private :
    void eat(){
        std :: cout << "sparrow eats"<< std::endl;
    }
    public:
    void fly(){
        std::cout << "sparrow eats" << std::endl ;

    }
};

class eagle : public Bird{

    public :
        void eat(){
            std::cout << "Eagle eats" << std :: endl;
        }
        void fly(){
            std::cout<< "eagle flys" << std:: endl;
        }
};

#endif