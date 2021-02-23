#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

void printData(future<int>& f)
{
int data = f.get();
cout<<"Value from printData:"<<data<<endl;
}

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
packaged_task<int(int)> task1(performAddition);
packaged_task<bool(int)> task2(is_prime);
future<int> fObj = task1.get_future();
future<bool> fObj1 = task2.get_future();
thread t1(move(task1),10);
thread t2(printData,ref(fObj));
thread t3(move(task2),3000023);
for(int i=1;i<5;++i)
{
cout <<"Working in main:"<<i<<endl;
this_thread::sleep_for(chrono::milliseconds(300));
}
bool result = fObj1.get();
cout << boolalpha << "Is 3000023 prime:"<<result <<endl;
t1.join();
t2.join();
t3.join();
return 0;
}