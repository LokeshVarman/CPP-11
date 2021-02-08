#include<iostream>
#include <initializer_list>
#include <algorithm>

using namespace::std;

class IntArray{

  private:
  int *p;
  int size;

public:
  IntArray();
  IntArray(int size);
  IntArray(const initializer_list<int> &list);
  ~IntArray();
  int &operator[](int i);
};

IntArray::~IntArray()
{
  delete []p;
  p = nullptr;
}
IntArray::IntArray()
{
  p = nullptr;
};

IntArray::IntArray(int s):size(s)//initialization list
{
    p = new int[size];
}

IntArray :: IntArray(const initializer_list<int> &list):IntArray(list.size())
{
  int c=0;
  for(auto & ele : list)
  {
    p[c]=ele;
    c++;
  }
}

int &IntArray::operator[](int i) {
            return p[i];
};

int main()
{
IntArray obj {3,4,5,6,7};
/*for(int i =0;i<3;i++)
{
obj[i]=i+1;
}*/
for(int i=0;i<5;i++)
{
cout << obj[i]<<endl;
}
return 0;
}