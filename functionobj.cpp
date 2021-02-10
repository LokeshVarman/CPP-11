#include <iostream>
using namespace std;

class AddVal
{
	int val;
	public:
  AddVal(int x);
	int operator ()(int input);
};

AddVal :: AddVal(int x): val(x)
{

}
int AddVal:: operator()(int input)
{
  return val+input;
}

int main()
{
  AddVal add5(5);
//add5();
cout <<add5(6) <<endl;// 11
cout<< add5(7)<<endl;// 12

AddVal add7(7);
//add7();
cout <<add7(6)<<endl;// 13
cout << add7(8)<<endl;// 14


}