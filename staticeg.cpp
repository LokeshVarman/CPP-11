#include <stdio.h>
#include<iostream>
using namespace std;
class test{
    int testcode;
    static int count;
    public:
    void setcount(){
        testcode=++count;
    }
    int getcount(){
        return testcode;
    }
    static void testcount(){
        cout<<"Number of tests conducted:"<<count<<endl;
    }
};
int test::count;
int main()
{
    test t1,t2;
    t1.setcount();
    t2.setcount();
    test::testcount();
    
    test t3;
    t3.setcount();
    test::testcount();
    cout<<"Details:"<<endl;
    cout<<t1.getcount()<<endl;
    cout<<t2.getcount()<<endl;
    cout<<t3.getcount()<<endl;
    
}