#include <iostream>
using namespace std;

class Shape {
public:
    Shape(){
        cout<<"Shape Constructor"<<endl;
    }
    void draw() {
        cout << "This is a shape.\n";
    }
    ~Shape(){
        cout<<"Shape Destructor"<<endl;
    }
};




int main() {
    //Shape sobj;
    Shape *sobj = new Shape();
    delete(sobj);

    return 0;
}


