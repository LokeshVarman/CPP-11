#include<iostream>
#include<cassert>

using namespace std;
int main(){
    
  static_assert(sizeof(long)==8,"long must be 8 bytes");
  static_assert(sizeof(int)==2,"int must be 4 bytes");
  
    int b=2;
    cout<<b;
    cout<<a;
  return 0;
    
}
