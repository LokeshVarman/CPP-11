#include<iostream>
#include<type_traits>

using namespace std;

template <typename T>
class A{
    public:
    
    T foo(T i){
        static_assert(is_integral<T>::value,"int required");
        return (i * 2);
    }
    private:
    T x;
};
int main(){
    A<double> a;
    cout<<a.foo(3)<<endl;
    return 0;
}
