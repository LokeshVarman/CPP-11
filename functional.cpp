#include<iostream>
#include<functional>
using namespace std;
struct Num{
     int num;
    Num(int num):num(num){}
    void print_add(int i) const{ cout<<num+i<<"\n";}
    
   
};
void print_num(int i){
    cout<<i<<"\n";
}
int main(){
    function<void(int)> fDisplay=print_num;
    fDisplay(-9);
    //lambda
    function<void()> fDisplayLamba=[](){
        print_num(44);
    };
    fDisplayLamba();
    //cal to member function
    function<void(const Num&, int)> fAddDisplay=&Num::print_add;
    Num n1(234);
    fAddDisplay(n1,1);
    
    
}