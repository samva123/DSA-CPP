#include <iostream>
#include "bird.h"


using namespace std;

void birddosome(Bird*&bird){
    bird->eat();
    bird->fly();
    bird->eat(); 
}

int main(){
    Bird*bird = new Sparrow();
    Sparrow*sp = new Sparrow();
    // sp->eat; it is inaccessible
    birddosome(bird);
     

}