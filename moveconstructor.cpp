#include <iostream>
using namespace std;

class A{
	int p;
	
	public:
	A()
	{
		p=0;
		
	}
	A(int v)
	{
		p=v;
		cout << "para called"<<endl;
	}
	
	A(const A &o)=delete;
	
	A(A &&o)
	{
	 p = o.p;
	 //o.p=nullptr;
	 cout << "Move cotr called"<<endl;
	}
	
	void disp()
	{
		cout << "value" <<p<<endl;
	}
	
	A& operator=(A &&o)
	{
	    p=o.p;
	    cout << "Move Assignemnt"<<endl;
	}
		
};

class myList{
    
    A obj;
    public:
    myList(A &o): obj(std::move(o))
    {
        cout << "Lvalue called"<<endl;
    }
    myList(A &&o): obj(std::move(o)){
        cout <<"RValue called"<<endl;
    }
};

int main()
{
   A o1(10);
   
   myList l1(o1);
   myList l3(A(10));
   A o2;
   o2 = A(20);
   //A o3(std::move(A(30)));
  }