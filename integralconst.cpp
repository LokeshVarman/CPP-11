#include <iostream>
#include <type_traits>

enum class my_e {
       e1,
       e2
    };
typedef std::integral_constant<my_e, my_e::e1> my_e_e1;
typedef std::integral_constant<my_e, my_e::e2> my_e_e2;
 
void fun1(my_e var)
{
    if(my_e_e2::value==var)
    {
 	std::cout << "var is same as my_e::e2"<<static_cast<int>(var)<<std::endl;
    }
    else
    {
            std::cout<< "not same"<<std::endl;
    }
}

int main() 
{
    typedef std::integral_constant<int, 2> two_t;
    typedef std::integral_constant<int, 4> four_t;
 
//  static_assert(std::is_same<two_t, four_t>::value,
//                "two_t and four_t are not equal!"); 
//  error: static assertion failed: "two_t and four_t are not equal!"
 
    static_assert(two_t::value*2 == four_t::value,
       "2*2 != 4"
    );
    std::cout<< two_t::value<<std::endl;
    fun1(my_e::e2);
    fun1(my_e::e1);
     
}