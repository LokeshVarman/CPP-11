//Returning from thread
#include <iostream>
#include <thread>
#include <string>
using namespace std;
void function1(const string &s, string &r)
{
r = s+"from function1.";
}
struct DataClass
{
const string& s;
string *r;
DataClass(const string& str, string *rst):s(str), r(rst)
{
}
void operator()()
{
*r=s+"From functionObject class";
}
};
int main()
{
string s = "This is a string";
string r1, r2;
thread t1(function1,s,ref(r1));
thread t2(DataClass(s,&r2));
t1.join();
t2.join();
cout << "r1:"<<r1<<endl;
cout << "r2:"<<r2<<endl;
return 0;
}