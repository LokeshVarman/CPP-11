#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
int out;
int performAddition(int a,int b)
{
out=a+b;
return out;
}
int performsubtract(int a,int b)
{
out=a-b;
return out;
}
int performmultiply(int a,int b)
{
out=a*b;
return out;
}
int performdivision(int a,int b)
{
out=a/b;
return out;
}
int main()
{
int s,s1,s2,s3;
future<int> fObj = std::async(performAddition,10,5);
future<int> fObj1 = std::async(performsubtract,10,5);
future<int> fObj2 = std::async(performmultiply,10,5);
future<int> fObj3 = std::async(performdivision,10,5);
for(int i=1;i<5;++i)
{
cout <<"Working in main:"<<i<<endl;
this_thread::sleep_for(chrono::milliseconds(300));
}
int addRes = fObj.get();
int subRes = fObj1.get();
int mulRes = fObj2.get();
int divRes = fObj3.get();
cout<<"add is: " <<addRes<<endl;
cout<<"Subtract is: " <<subRes<<endl;
cout<<"multiply is: " <<mulRes<<endl;
cout<<"division is: " <<divRes<<endl;
return 0;
}