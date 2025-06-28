#include<iostream>
using namespace std;
class Student
{
private:
    double mark;
public:
    Student(double mark)
    {
        this->mark=mark;
    }
    double getMark()
    {
        return mark;
    }
};
void avgMark(Student &obj1,Student &obj2)
{
    double avgMark;
    avgMark=(obj1.getMark()+obj2.getMark())/2;
    cout<<"average mark = "<<avgMark;
}
int main()
{
    double num1,num2;
    cout<<"enter two mark = ";
    cin>>num1>>num2;
    Student obj1(num1),obj2(num2);
    avgMark(obj1,obj2);
}
