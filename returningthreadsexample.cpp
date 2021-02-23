#include <iostream>
#include <thread>
#include <string>
using namespace std;
void add(int a, int b, int &out)
{
out = a+b;
}
void subtract(int a, int b, int &out)
{
out = a-b;
}
int main()
{

int c,d;
thread t1(add,10,5,ref(c));
thread t2(subtract,10,5,ref(d));
t1.join();
t2.join();
cout << "r1:"<<c<<endl;
cout << "r2:"<<d<<endl;
return 0;
}