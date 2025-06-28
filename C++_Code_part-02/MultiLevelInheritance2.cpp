#include<iostream>
using namespace std;
class Person
{
public:
    string name;
    int age;
   void display()
   {
       cout<<"name = "<<name<<endl;
       cout<<"age = "<<age<<endl;
   }
};
class Employee:public Person
{
public:
    string empID;
    void display2()
    {
        cout<<"empID = "<<empID<<endl;
    }
};
class Manager :public Employee
{
public:
    string dep;
    void display3()
    {
        cout<<"Depertment = "<<dep<<endl;
    }
};
int main()
{
    Person obj1;
    string name1,name2,name3,empID2,empID3,dep3;
    int age1,age2,age3;
    cout<<"name1 = ";
    cin>>name1;
    cout<<"age1 = ";
    cin>>age1;
    cout<<"name2 = ";
    cin>>name2;
    cout<<"age2 = ";
    cin>>age2;
    cout<<"ID2 = ";
    cin>>empID2;
    cout<<"name3 = ";
    cin>>name3;
    cout<<"age3 = ";
    cin>>age3;
    cout<<"ID3 = ";
    cin>>empID3;
    cout<<"dep = ";
    cin>>dep3;
    obj1.name=name1;
    obj1.age=age1;
    Employee obj2;
    obj2.name=name2;
    obj2.age=age2;
    obj2.empID=empID2;
    Manager obj3;
    obj3.name=name3;
    obj3.age=age3;
    obj3.empID=empID3;
    obj3.dep=dep3;
    obj1.display();
        obj2.display();
    obj2.display2();
    obj3.display();
    obj3.display2();
    obj3.display3();


}
