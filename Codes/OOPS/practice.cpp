#include <iostream>
using namespace std;

class Student
{
public:
    int id;
    int age;
    string name;
    int nos;

    Student()
    {
        cout << "ctor called" << endl;
    }

    Student(int _id, string _name, int _age, int _nos)
    {

        this->id = _id;
        this->name = _name;
        this->age = _age;
        this->nos = _nos;
        cout << "parameter called " << endl;
    }

    Student(const Student &srcobj)
    {
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->id = srcobj.id;
        this->nos = srcobj.nos;
        cout << "copy called" << endl ;
    }

    void study()
    {
        cout << "study" << endl;
    }
    void sleep()
    {
        cout << "sleep" << endl;
    }
};

int main()
{
    cout << sizeof(Student) << endl;
    int a;
    Student s1(1, "varun ", 15, 5);
    s1.name = "sam";

    // s1.age = 19 ;
    // s1.id = 1;

    Student s3 = s1; // this will do shallow copy
    // Student s3(s1) ;
    cout << s1.name << endl;
    cout << s3.name << endl;

    // Student s2;
    // // s2.name = "rajat";
    // s2.age = 17;
    // s2.id = 2;
    // cout << s2.name << endl;

    // Student *s4 = new Student(3, "anmol", 24, 5);
    // cout << s4->name << endl;
    // cout << (*s4).age << endl;
    // s4.name will give error because it is alloaced in heap and stack will contain a block name s4 that contains the address of heap data

    // delete s4 ;
}