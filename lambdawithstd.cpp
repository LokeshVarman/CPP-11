//using function pointer and function as well....

#include <iostream>
#include<functional>
using namespace std;

//type def for function pointer
typedef void (*fp) (int,int);

//having callback function
void execute(function<void(int,int)> operations[],int a,int b,int intOperations)
//void execute(fp operations[],int a,int b,int intOperations)
{
    for(int i=0;i<intOperations;++i)
        operations[i](a,b);
}

int main() 
{
    int a = 10;
    int b = 3;
    
    //define lambdas
    auto add = [](int a,int b)->void
    {
        cout << a << " + " << b << " = " << (a+b) << endl; 
    };
    auto substract = [](int a,int b)
    {
        cout << a << " - " << b << " = " << (a-b) << endl; 
    };
    auto multiply = [](int a,int b)
    {
        cout << a << " * " << b << " = " << (a*b) << endl; 
    };
    auto devide = [](int a,int b)
    {
        cout << a << " / " << b << " = " << (a/b) << endl; 
    };
    auto reminder = [](int a,int b)
    {
        cout << a << " % " << b << " = " << (a%b) << endl; 
    };

    //create function pointer array
    function<void(int,int)> operations[] = {add,substract,multiply,devide,reminder};
    //fp operations[] = {add,substract,multiply,devide,reminder};

    //call for 3 operations
    execute(operations,a,b,3);

    cout << "__________________________" << endl << endl;

     //call for 5 operations
    execute(operations,a,b,5);

    return 0;
}