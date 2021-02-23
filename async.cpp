#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
int performAddition(int n)
{
int sum =0;
for(int i=0;i<n;++i)
{
sum += i;
this_thread::sleep_for(chrono::milliseconds(300));
}
return sum;
}
bool is_prime(int n)
{
bool st = true;
for(int i =2;i<n;++i){
if(n%i == 0)
{
st=false;
break;
}
}
return(st);
}
int main()
{
future<int> fObj = std::async(performAddition,10);
future<bool> fObj1 = async(is_prime,3000023);
for(int i=1;i<5;++i)
{
cout <<"Working in main:"<<i<<endl;
this_thread::sleep_for(chrono::milliseconds(300));
}
bool result = fObj1.get();
int addRes = fObj.get();
cout << boolalpha << "Is 3000023 prime:"<<result <<endl;
cout<<"Sum is: " <<addRes<<endl;
return 0;
}