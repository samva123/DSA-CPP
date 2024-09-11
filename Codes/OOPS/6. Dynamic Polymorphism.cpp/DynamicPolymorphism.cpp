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
    ~Animal(){
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

    // Animal *animalPtr;
    // Dog dogObj;
    // Cat catObj;

    // animalPtr = &dogObj;
    // animalPtr->makeSound(); // Output: "Dog barks"

    // animalPtr = &catObj;
    // animalPtr->makeSound(); // Output: "Cat meows"

    return 0;
}
