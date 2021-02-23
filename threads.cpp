#include <iostream>
#include <thread>
void thread_function()
{
for(int i = 1; i < 2; i++);
std::cout<<"thread function Executing"<<std::endl;
}
class DisplayThread
{
public:
void operator()()
{
for(int i = 1; i < 2; i++)
std::cout<<"Display Thread Executing"<<std::endl;
}
};
int main()
{
std::thread threadObj1(thread_function);
std::thread threadObj2( (DisplayThread()) );
for(int i = 1; i < 2; i++);
std::cout<<"Display From MainThread"<<std::endl;
threadObj1.join();
std::cout<<"Waiting For Thread to complete"<<std::endl;
threadObj2.join();
std::cout<<"Exiting from Main Thread"<<std::endl;
return 0;
}