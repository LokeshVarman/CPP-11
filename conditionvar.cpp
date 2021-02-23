#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;
class DataHandle
{
	vector <int> v;
  condition_variable cv, pv;
  mutex m;
	static int i;
public:
	void insertdata()
	{
    //m.lock();
   // lock_guard<mutex> lockg(m);
   unique_lock<mutex> lck(m);
	while(i != 0)
		pv.wait(lck);
		for(int j=1;j<=10;++j)
		{
			cout<<"Value inserted:"<<i<<endl;
			v.push_back(i);
			++i;
			this_thread::sleep_for(chrono::milliseconds(300));
		}
    cv.notify_one();
    //m.unlock();
	}
	
	void deldata()
	{
   // m.lock();
   //lock_guard<mutex> lockg(m);
   unique_lock<mutex> lck(m);
	while(i == 0)
		cv.wait(lck);
		for(int j=1;j<=10;++j)
		{
			cout <<"Value deleted:"<<v.back()<<endl;
			v.pop_back();
			this_thread::sleep_for(chrono::milliseconds(700));
		}
    pv.notify_one();
   // m.unlock();
	}
};

int DataHandle::i=0;

int main()
{
	cout<<"Main started:"<<endl;
	DataHandle dataObject;
	thread producerThread(&DataHandle::insertdata,&dataObject);
	thread consumerThread(&DataHandle::deldata,&dataObject);
	
	producerThread.join();
	consumerThread.join();
	
	return 0;
}