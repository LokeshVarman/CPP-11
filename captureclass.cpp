#include <iostream>
using namespace  std;

int main()
{
  int z=7;
  int y=5;
  z=9;
    auto fun1=[z,y](int x)
    {
        cout << "Value of x:"<<x<<endl;
        cout << "Value of z:"<<z<<endl;
        cout << "Value of y:"<<y<<endl;
    };

    fun1(60);
    //z=9;
    fun1(90);
    
    int val=5;
    auto add5=[val](int input){return val+input; };
    cout << add5(6)<<endl;
    cout <<add5(7)<<endl;

    auto sub5=[val](int input){ return input-val;};
    cout <<"Sub5: "<<sub5(8)<<endl;

    auto updateVal=[&val](int input){ val=input; };
    updateVal(7);

    cout<< "updated Val:"<<val<<endl;
    auto sub7=[val](int input){ return input-val;};
    cout << "Sub7: "<<sub7(13)<<endl;
}