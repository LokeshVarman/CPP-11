#include <iostream>
#include <type_traits>
#include <typeinfo>
using namespace std;
/* Primary Type Traits:
is_array: must be a [] variable (not a pointer to an array)
is_class: class or struct (not union nor enum)
is_enum: enum or enum class
is_floating_point: float, double
is_function: function, function template (not lambda expression, nor class operator ())
is_integral: short, int, long, ...
is_lvalue_reference: & (not &&)
is_member_function_pointer: a pointer to a member function
is_member_object_pointer: a pointer to a member object
is_pointer: *, **
is_rvalue_reference: &&
is_union: union only
is_void: void (not void*) */



//function template
template<class T>
void func(T t)
{
cout << boolalpha << "type: " << typeid(t).name() << endl;
cout << boolalpha << "is_array: " << is_array<decltype(t)>::value << endl;
cout << boolalpha << "is_pointer: " << is_pointer<decltype(t)>::value << endl;
cout << boolalpha << "is_function: " << is_function<decltype(t)>::value << endl;
//static_assert(is_pointer<T>::value, "Argument type is not a function");
}




void add()
{



cout << "hello";
}



int main()
{
int a[4];
cout << boolalpha << "type: " << typeid(a).name() << endl;
cout << boolalpha << "is_array: " << is_array<decltype(a)>::value << endl;
func(a);
cout << endl; func([]() {}); //lambda expression argument (function argument)
cout << endl;
func(add);
cout <<endl;
cout << boolalpha <<"is_function: "<<is_function<decltype(add)>::value<<endl;
void *v;
cout << boolalpha << "is_void: " << is_void<decltype(v)>::value << endl;
return 0;
}