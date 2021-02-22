#include <iostream>
#include <type_traits>
using namespace std;

 /* Type Relationships is_base_of: is class A derived from base B? is_convertible: implicit conversion of A to B is_same: is A the same type as B? i.e. is it a typedef of B? */
struct A { };
struct B : A { };
typedef B C;

int main() {
cout << boolalpha << "is_base_of A, B: " << is_base_of<A, B>::value << endl;
cout << boolalpha << "is_base_of B, A: " << is_base_of<B, A>::value << endl;
cout << boolalpha << "is_convertible A to B: " << is_convertible<A, B>::value << endl;
cout << boolalpha << "is_convertible B to A: " << is_convertible<B, A>::value << endl;
cout << boolalpha << "is_same A, B: " << is_same<A, B>::value << endl;
cout << boolalpha << "is_same B, C: " << is_same<B, C>::value << endl;
cout << boolalpha << "is_same A, C: " << is_same<A, C>::value << endl;
static_assert(is_same<B, C>::value, "they are not the same!");
return 0;
}
