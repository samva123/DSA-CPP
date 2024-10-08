#include <iostream>


// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    // virtual
    virtual void makeSound()
    {
        std::cout << "Animal makes a sound" << std::endl;
    }
     virtual ~Animal(){
        std::cout << "Animal destructor" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Dog barks" << std::endl;
    }
    ~Dog(){
        std::cout << "dog destructor" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        std::cout << "Cat meows" << std::endl;
    }
};

void sound(Animal *&animal){
    animal -> makeSound();
}

int main()
{

    // Dog*dog = new Dog();
    // dog -> makeSound(); //PRINT DOG BARKS


    Animal *animal = new Dog();
    sound(animal);
    delete animal;

    // Dog *hello = new Animal();
    // Animal *hello = new Animal();
    // Animal *hello1 = new Dog();
    // Dog *hello2 = new Dog();

    // sound(hello);

    // Animal *animalPtr;
    // Dog dogObj;
    // Cat catObj;

    // animalPtr = &dogObj;
    // animalPtr->makeSound(); // Output: "Dog barks"

    // animalPtr = &catObj;
    // animalPtr->makeSound(); // Output: "Cat meows"


    // Animal *animal = new Animal();
    // Dog *dog = dynamic_cast<Dog*>(animal); // Attempting downcast

    // if (dog) {
    //     dog->makeSound();
    // } else {
    //     std::cout << "Downcasting failed!" << std::endl;
    // }

    // delete animal;
    // return 0;

    
}


// things are not working without virtual and override because all
// things are working a compile time so that is why animal is sounding 
// whether the object is of animal or not
