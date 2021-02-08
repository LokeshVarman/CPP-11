#include<iostream>
using namespace::std;

class IntArray{

  private:
  int *p;
  int size;

public:
  IntArray();
  IntArray(int size);
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

IntArray::IntArray(int size)
{
  this->size = size;
  p = new int[size];
}

int &IntArray::operator[](int i) {
            return p[i];
};

int main()
{
IntArray obj(3);
for(int i =0;i<3;i++)
{
obj[i]=i+1;
}
for(int i=0;i<3;i++)
{
cout << obj[i]<<endl;
}
return 0;
}