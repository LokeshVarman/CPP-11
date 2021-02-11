#include<iostream>
#include<memory>
using namespace std;
struct tsk
{
    int ids;
    tsk (int id):ids(id)
    {
        cout<<"tsk constructor"<<endl;
    }
    ~tsk()
    {
        cout<<"tsk destructor"<<endl;
    }
};
int main()
{
    unique_ptr<tsk> tskptr(new tsk(4));
    if(tskptr)
    cout<<"tskptr is not empty"<<endl;
    cout<<tskptr->ids<<endl;
    cout<<"reseting the tskptr"<<endl;
    tskptr.reset();
    

    if(!tskptr)
    cout<<"tskptr is empty "<<endl;
    
    unique_ptr<tsk> tskptr2(new tsk(1));{
        unique_ptr<tsk> tskptr4=move(tskptr2);
        if(!tskptr2)
        cout<<"tskptr2 is empty"<<endl;
        cout<<tskptr4->ids<<endl;
        
    }
    return 0;
}