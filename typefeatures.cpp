#include <iostream>
#include <type_traits>
using namespace std;

/* Type Features:
has_virtual_destructor: virtual ~class() {} defined
is_assignable: Is A = B for types A and B defined? Not necessarily B = A.
is_constructible: Can the object be constructed given a set of argument types?
is_copy_assignable: operator= (assignment operator) is available (implicitly is ok)
is_copy_constructible: copy constructor available (not deleted/suppressed)
is_destructible: destructor not suppressed
is_default_constructible: is there a default constructor (without parameters) available?
is_move_assignable: Move assignment defined or implicit
is_move_constructible: Move constructor defined or implicit
is_trivially_assignable: i.e. implicit assignment (not assignment overloaded)
is_trivially_constructible: implicit constructor
is_trivially_copy_assignable is_trivially_copy_constructible
is_trivially_destructible is_trivially_default_constructible
is_trivially_move_assignable
is_trivially_move_constructible
is_nothrow_assignable: noexcept
is_nothrow_constructible
is_nothrow_copy_assignable
is_nothrow_copy_constructible
is_nothrow_destructible
is_nothrow_default_constructible
is_nothrow_move_assignable
is_nothrow_move_constructible */

struct X { virtual ~X() {} };
struct A { };
struct B : A
{
B& operator= (const A&)
{ return *this; }
};
struct C {
C(C&&){}
}; //copy-constructible

struct D {
D() = delete;
D(D&&) = delete;
}; //not copy/move-constructible

struct E { E(const E&) = delete; }; //no copy constructor
struct G { 
    G() noexcept {}; //nothrow (default) constructible
};
struct H{ H(const char*) {}; };
int main()
{
cout << boolalpha << "has_virtual_destructor X: " << has_virtual_destructor<X>::value << endl;
cout << boolalpha << "is_assignable A=B: " << is_assignable<A, B>::value << endl;
cout << boolalpha << "is_assignable B=A: " << is_assignable<B, A>::value << endl;
cout << boolalpha << "is_trivially_assignable A,B: " << is_trivially_assignable<A, B>::value << endl;
cout << boolalpha << "is_trivially_assignable B,A: " << is_trivially_assignable<B, A>::value << endl;
cout << boolalpha << "is_constructible H,string: " << is_constructible<H, string>::value << endl;
cout << boolalpha << "is_constructible H,const char*: " << is_constructible<H, const char*>::value << endl;
cout << boolalpha << "is_copy_constructible A: " << is_copy_constructible<A>::value << endl;
cout << boolalpha << "is_copy_constructible E: " << is_copy_constructible<E>::value << endl;
cout << boolalpha << "is_default_constructible A: " << is_default_constructible<A>::value << endl;
cout << boolalpha << "is_default_constructible D: " << is_default_constructible<D>::value << endl;
cout << boolalpha << "is_trivially_constructible A: " << is_trivially_constructible<A>::value << endl;
cout << boolalpha << "is_trivially_constructible D: " << is_trivially_constructible<D>::value << endl;
cout << boolalpha << "is_nothrow_constructible G: " << is_nothrow_constructible<G>::value << endl;
cout << boolalpha << "is_nothrow_constructible C: " << is_nothrow_constructible<C>::value << endl;
static_assert(is_nothrow_constructible<G>::value, "nothrow constructible");
return 0;
}
