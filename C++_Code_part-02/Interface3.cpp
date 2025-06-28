#include<iostream>
using namespace std;
class Vehicle
{
public:
    virtual void start()=0;
    virtual void stop()=0;
};
class Car:public Vehicle
{
public:
    void start()
    {
        cout<<"start the car."<<endl;
    }
    void stop()
    {
        cout<<"stop the car."<<endl;
    }
};
class Bike:public Vehicle
{
public:
    void start()
    {
        cout<<"start the bike."<<endl;
    }
    void stop()
    {
        cout<<"stop the bike."<<endl;
    }
};
int main()
{
    Car obj1;
    Bike obj2;
    obj1.start();
    obj1.stop();
    obj2.start();
    obj2.stop();
}
