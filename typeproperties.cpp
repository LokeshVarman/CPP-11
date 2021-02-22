#include <iostream>
#include <type_traits>
using namespace std;

/* Type properties:
is_abstract: has a pure virtual function
is_const: is const-qualified
is_empty: no non-static members, no virtual functions, no virtual base class, i.e. cannot store data
is_literal_type: can be a constexpr. scalar types, references, and simple classes, structs, unions.
is_pod: "plain old data type". C language compatible structures and classes (no constructors), including scalar types.
is_polymorphic: has a virtual function or inherits one.
is_signed: arithmetic type and -1 < 0
is_standard_layout: scalar types and classes, structs, and unions subject to certain restrictions ***
is_trivial: scalars and classes, structs, unions subject to certain restrictions ***
is_trivially_copyable: scalar types and objects that use copy and move constructors (implicitly) and assignments
is_unsigned: arithmetic type and 0 < -1
is_volatile: type qualified as volatile */

struct X { virtual void fn() = 0; }; //has a pure virtual function
struct A { };

struct D {
D(){};
~D() {};
};

struct E {
E(E&) = delete;
E(const E&) = delete;
}; //no copy constructor

enum class G { };
class H { };

int main()
{
cout << boolalpha << "is_abstract X: " << is_abstract<X>::value << endl;
cout << boolalpha << "is_empty A: " << is_empty<A>::value << endl;
cout << boolalpha << "is_empty G: " << is_empty<G>::value << endl;
cout << boolalpha << "is_pod A: " << is_pod<A>::value << endl;
cout << boolalpha << "is_pod D: " << is_pod<D>::value << endl;
cout << boolalpha << "is_polymorphic X: " << is_polymorphic<X>::value << endl;
cout << boolalpha << "is_polymorphic A: " << is_polymorphic<A>::value << endl;
cout << boolalpha << "is_standard_layout D: " << is_standard_layout<D>::value << endl;
cout << boolalpha << "is_standard_layout X: " << is_standard_layout<X>::value << endl;
cout << boolalpha << "is_trivial G: " << is_trivial<G>::value << endl;
cout << boolalpha << "is_trivial X: " << is_trivial<X>::value << endl;
cout << boolalpha << "is_literal_type H: " << is_literal_type<H>::value << endl;
cout << boolalpha << "is_literal_type X: " << is_literal_type<X>::value << endl;
volatile int vi;
int i;
cout << boolalpha << "is_volatile vi: " << is_volatile<decltype(vi)>::value << endl;
cout << boolalpha << "is_volatile i: " << is_volatile<decltype(i)>::value << endl;
static_assert(is_volatile<decltype(vi)>::value, "volatile"); return 0;
}
