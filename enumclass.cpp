#include <iostream>
using namespace std;

enum class color
{
  RED =1,
  GREEN,
  YELLOW
};

enum class Fruit
{
  apple=1,
  cherry,
  pineapple
} ;

void printVal(color a)
{
  cout<<"\nThe integer value of color"<<static_cast<int>(a);
}
void printVal(Fruit a)
{
  cout<<"\nThe integer value of Fruit "<<static_cast<int>(a);
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
color c1=static_cast<color>(ch);
printVal(c1);
printVal(ch);//it should give error

 cout<< "\nenter Fruit choice (1: APPLE, 2: CHERRY, 3: PINEAPPLE)";
cin>>ch;
Fruit f1=(Fruit)ch;
printVal(f1);
printVal(ch);//it should give error
return 0;
}