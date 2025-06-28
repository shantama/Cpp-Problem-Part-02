#include<iostream>
using namespace std;
class Animal
{
public:
    string species;
    void display1()
    {
    cout<<"species is "<<species<<endl;

    }
};
class Pet
{
public:
    string name;
    void display2()
    {
        cout<<"name is "<<name<<endl;
    }
};
class Dog:public Animal,public Pet
{
public:
    string breed;
    void display3()
    {
        cout<<"breed is "<<breed<<endl;
    }
};
int main()
{
    Animal obj1;
    obj1.species="mamel";
    obj1.display1();
    Pet obj2;
    obj2.name="dog";
    obj2.display2();
    Dog obj3;
    obj3.species="reptail";
    obj3.name="crocodail";
    obj3.breed="dengarous";
    obj3.display1();
    obj3.display2();
    obj3.display3();


}
