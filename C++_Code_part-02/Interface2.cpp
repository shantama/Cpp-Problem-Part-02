#include<iostream>
#include<cmath>
using namespace std;
class Shape
{
public:
    virtual double getArea()=0;
    virtual double getPerimeter()=0;
};
class Triangle:public Shape
{
public:
    double a,b,c,s,result;
    double getArea()
    {
        s=(a+b+c)/2;
        result=sqrt(s*(s-a)*(s-b)*(s-c));
        return result;
    }
    double getPerimeter()
    {
        return a+b+c;
    }
};
class Square:public Shape
{
public:
    double a;
    double getArea()
    {
        return a*a;
    }
    double getPerimeter()
    {
        return 4*a;
    }
};
int main()
{
    Triangle obj1;
    obj1.a=5;;
    //ptr->a=10;
    obj1.b=20;
    obj1.c=15;
    cout<<"area of triangle = "<<obj1.getArea()<<endl;
    cout<<"perimeter of triangle = "<<obj1.getPerimeter()<<endl;
    Square obj2;
    obj2.a=5;
    cout<<"area of square = "<<obj2.getArea()<<endl;
    cout<<"perimeter of square = "<<obj2.getPerimeter()<<endl;




}
