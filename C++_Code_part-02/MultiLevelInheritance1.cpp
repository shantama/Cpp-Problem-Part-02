#include<iostream>
using namespace std;
class Vehicle
{
private:
    string make,model;
public:
    void setMake(string make)
    {
        this->make=make;
    }
    void setModel(string model)
    {
        this->model=model;
    }
    string getMake()
    {
        return make;
    }
    string getModel()
    {
        return model;

    }
    void display1()
    {
        cout<<"make = "<<make<<endl;
        cout<<"model = "<<model<<endl;
    }
};
class Car:public Vehicle
{
private:
    int num_doors;
public:
    void setNum_doors(int num_doors)
    {
        this->num_doors=num_doors;
    }
    void display2()
    {
        cout<<"num_doors = "<<num_doors<<endl;
    }
};
class ElectricCar:public Car
{
private:
    string battery_life;
public:
    void setBattery_life(string battery_life)
    {
        this->battery_life=battery_life;
    }
    void display3()
    {
        cout<<"battery life = "<<battery_life<<endl;
    }
};
int main()
{
   Vehicle obj1;
   obj1.setMake("toyota") ;
   obj1.setModel("A4c");
   obj1.display1();
   Car obj2;
   obj2.setMake("honda") ;
   obj2.setModel("A3c");
   obj2.setNum_doors(4);
   obj2.display1();
   obj2.display2();
   ElectricCar obj3;
    obj3.setMake("honda") ;
   obj3.setModel("B3c");
   obj3.setNum_doors(4);
   obj3.setBattery_life("12 hour");
   obj3.display1();
   obj3.display2();
   obj3.display3() ;























}
