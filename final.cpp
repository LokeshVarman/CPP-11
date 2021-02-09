#include <iostream>
using namespace std;

class Acls
{
    public:
    virtual void fun1(int a)=0;
    virtual void fun3(int a)=0;
    virtual void fun2() const
    {
        cout <<"from A fun2 called"<<endl;
    }
};
class Bcls: public Acls
{
    public:
    virtual void fun3(int b) final
    {
        cout << "fun 3 value "<< b<<endl;
    }
    virtual void fun2() const override
    {
        cout<< "fun2 called"<<endl;
    }
    virtual void fun1(int b) override
    {
        cout << "value "<< b<<endl;
    }
};

class Ccls: public Bcls
{
    /*void fun3(int b)
    {
        cout <<"fun3 from C"<<b<<endl;
    }*/
};
int main()
{
    Acls *pta = nullptr;
    const Bcls obj;
    Bcls obj1;
    obj.fun2();
    
    pta = & obj1;
    pta->fun1(2);
    
}