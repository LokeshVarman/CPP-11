#include <iostream>
#include <thread>
#include <atomic>
using namespace std;
atomic<int> sharedData;
void consumer()
{
while(sharedData == 0)
this_thread::yield();
cout << "Shared data consumed is: "<< sharedData <<endl;
}
void producer(int d)
{
while(sharedData != 0)
this_thread::yield();
sharedData = d;
}
int main()
{
thread consumers[5], producers[5];
for(int i=0;i<5;i++)
{
consumers[i] = thread(consumer);
producers[i]=thread(producer,i+1);
}
for(int i=0;i<5;i++)
{
consumers[i].join();
producers[i].join();
}
return 0;
}