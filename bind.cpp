#include <iostream>

#include <functional>

using namespace std;

using namespace std::placeholders;



double my_devide(double a,double b)

{

    return (a/ b);

}



struct myPair

{

    int a;

    int b;

    double multiply()

    {

        return (a*b);

    }

};



int main() 

{

    //auto fn_5 = bind(my_devide,10,2);

    function<double()> fn_5 = bind(my_devide,10,2);

    cout << fn_5() << endl;



    //auto fn_half = bind(my_devide,_1,2);

    function<double(double)> fn_half = bind(my_devide,10,2);

    cout << fn_half(10) << endl;



    auto fn_invert = bind(my_devide,_2,_1);

    cout << fn_invert(10,2) << endl;



    myPair ten_two {10,2};

    

    auto fn_MemFn = bind(&myPair::multiply,_1);

    cout << fn_MemFn(ten_two) << endl;



    auto fn_MemData = bind(&myPair::b,ten_two);

    cout << fn_MemData() << endl;



    return 0;
}