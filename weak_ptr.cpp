
#include <iostream>
#include<memory>
using namespace std;
struct A{
    int x;
    A(int x): x(x){
        cout<<"hello";
    }
    ~A(){
        cout<<"destructor bye";
    }
};
weak_ptr<A> show()
{
    auto a=make_shared<A>(12);
    cout<<a->x<<endl;
    return a;
}
int main()
{
    auto a =show();
    cout<<"after show()"<<endl;
    if (a.expired())
        cout<<"expired";
    else
        cout<<a.lock()->x<<endl;

    
}
