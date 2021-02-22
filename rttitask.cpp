#include <iostream>
using namespace std;

class clsPerson
{
    public:
        virtual void display()
        {
            cout << "Hi from Person class" << endl;
        }
        virtual ~clsPerson() = default;
};

class clsEmployee : public clsPerson
{
    public:
        void display()
        {
            cout << "Hi from Employee class" << endl;
        }
        void display2()
        {
            cout << "Hello from Employee class" << endl;
        }
};

void callFun(clsPerson* ptr)
{
    ptr->display();
    if(typeid(*ptr).name()==typeid(clsEmployee).name())
    {
        clsEmployee* p_Employee = dynamic_cast<clsEmployee*> (ptr);
        p_Employee->display2();
    }
}

int main() 
{
    clsEmployee obj_Employee;
    clsPerson obj_Person;

    callFun(&obj_Employee);
    cout << endl << "****************************" << endl;
    callFun(&obj_Person);

    return 0;
}