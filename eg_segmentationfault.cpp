#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;
class DataHandle
{
vector <int> v;
static int i;
public:
void insertdata()
{
for(int j=1;j<=10;++j)
{
cout<<"Value inserted:"<<i<<endl;
v.push_back(i);
++i;
this_thread::sleep_for(chrono::milliseconds(300));
}
}
void lastdata()
{
for(int j=1;j<=10;j++)
{
cout<<"last data:" <<v.back()<<endl;
this_thread::sleep_for(chrono::milliseconds(100));
}
}
void deldata()
{
for(int j=1;j<=10;++j)
{
cout <<"Value deleted:"<<v.back()<<endl;
v.pop_back();
this_thread::sleep_for(chrono::milliseconds(700));
}
}
};
int DataHandle::i=1;
int main()
{
cout<<"Main started:"<<endl;
DataHandle dataObject;
thread producerThread(&DataHandle::insertdata,&dataObject);
thread consumerThread(&DataHandle::lastdata,&dataObject);
thread delThread(&DataHandle::deldata,&dataObject);
producerThread.join();
consumerThread.join();
delThread.join();
return 0;
}