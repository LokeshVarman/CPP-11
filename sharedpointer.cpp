#include<iostream>
#include<memory>
using namespace std;
class sample{
    public:
    void display(){
        cout<<"you are in A-Display"<<endl;
    }
};
int main(){
    shared_ptr<sample> p (new sample);
    cout<<p.get()<<endl;
    p->display();
    shared_ptr<sample> p1(p);
    p1->display();
    cout<<p.get()<<endl;
    cout<<p1.get()<<endl;
    //obj coun
    cout<<p.use_count()<<endl;
    cout<<p1.use_count()<<endl;
    //reset
    p.reset();
    cout<<p.get()<<endl;
    cout<<p1.use_count()<<endl;
    cout<<p1.get()<<endl;
    return 0;
}