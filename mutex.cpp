#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
using namespace std;

class DataHandle

{

  vector <int> v;

mutex m;

  static int i;

public:

  void insertdata()

  {

//m.lock();

lock_guard<mutex> lockg(m);

    for(int j=1;j<=10;++j)

    {

      cout<<"Value inserted:"<<i<<endl;

      v.push_back(i);

      ++i;

      this_thread::sleep_for(chrono::milliseconds(300));

    }

//m.unlock();

  }
  void deldata()
  {
// m.lock();
lock_guard<mutex> lockg(m);

    for(int j=1;j<=10;++j)

    {

      cout <<"Value deleted:"<<v.back()<<endl;

      v.pop_back();

      this_thread::sleep_for(chrono::milliseconds(700));

    }

// m.unlock();

  }
};
int DataHandle::i=1;
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