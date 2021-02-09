#include <iostream>
using namespace std;

typedef enum 
{
  RED =1,
  GREEN,
  YELLOW
}color;

typedef enum
{
  apple=1,
  cherry,
  pineapple
} Fruit;
//template<typename T1>
void printVal(color a)
{
  cout<<"\nThis is color"<<a;
}
void printVal(Fruit a)
{
  cout<<"\nThis is fruit value "<<a;
}
void printVal(int a)
{
  cout<<"\n This is integer val"<<a;
}
int main()
{
int ch;
cout<< "\nenter Color choice (1: RED, 2: GREEN, 3: YELLOW)";
cin>>ch;
color c1=(color)ch;
printVal(c1);
printVal(ch);//it should give error

 cout<< "\nenter Fruit choice (1: APPLE, 2: CHERRY, 3: PINEAPPLE)";
cin>>ch;
Fruit f1=(Fruit)ch;
printVal(f1);
printVal(ch);//it should give error
return 0;
}