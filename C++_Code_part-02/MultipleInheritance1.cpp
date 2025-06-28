#include<iostream>
using namespace std;
class Person
{
private:
    string name;
    int age;
public:
    void setName(string name)
    {
        this->name=name;
    }
    void setAge(int age)
    {
        this->age=age;
    }
    void display1()
    {
        cout<<"name = "<<name<<endl;
        cout<<"age = "<<age<<endl;
    }
};
class Address
{
protected:
    string street,city;
public:
    void setStreet(string street)
    {
        this->street=street;
    }
    void setCity(string city)
    {
        this->city=city;
    }
    void display2()
    {
        cout<<"street = "<<street<<endl;
        cout<<"city = "<<city<<endl;
    }
};
class Employee:public Person,public Address
{
private:
    int emp_id;
public:
    void setEmpid(int emp_id)
    {
        this->emp_id=emp_id;
    }
    void display3()
    {
        cout<<"ID = "<<emp_id<<endl;
    }
};
int main()
{
    Person obj1;
    obj1.setName("app");
    obj1.setAge(10);
    obj1.display1();
    Address obj2;
    //obj2.city="Dhaka";
    obj2.setStreet("kutubpur/A12");
    obj2.setCity("Dhaka");
    obj2.display2();
    Employee obj3;
    obj3.setName("ple");
    obj3.setAge(25);
    obj3.setStreet("kutubpur/A12");
    obj3.setCity("Dhaka");
    obj3.setEmpid(170);
    obj3.display1();
    obj3.display2();
    obj3.display3();











}
