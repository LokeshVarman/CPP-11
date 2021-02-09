#include <iostream>
using namespace std;
template <typename T1,typename T2>
auto add(T1 a, T2 b) -> decltype(a+b){
  return a+b;
}

int main()
{
  
  cout<<"first"<<add(2,3);
  cout<<"first"<<add(6.4,3);
}