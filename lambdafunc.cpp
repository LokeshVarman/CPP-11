
    

#include <iostream>

using namespace std;

int main()
{
    auto add = [](int a, int b) -> int
    {
       return (a+b);
    };
    auto subtract = [](int a, int b) -> int
    {
       return (a-b);
    };
    auto multiply = [](int a, int b) -> int
    {
       return (a*b);
    };
    auto divide = [](int a, int b) -> int
    {
          return (a/b);
    };
    auto remain = [](int a, int b) -> int
    {
       return (a%b);
    };
    cout << add(3,4) << endl;
    cout << subtract(3,4) << endl;
    cout << multiply(3,4) << endl;
    cout << divide(3,4) << endl;
    cout << remain(3,4) << endl;
    return 0;
}
 

 


