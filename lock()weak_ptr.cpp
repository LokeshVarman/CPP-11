#include <iostream>

#include <memory>

using namespace std;



class A

{

    public:

    int X;

    A(int X) : X(X) {}

    ~A() {cout << "Bye" << endl;}

};



weak_ptr<A> show()

{

    auto a = make_shared<A>(12);

    cout << a->X << endl;

    return a;

}



int main() 

{

   auto a = show();

   if(a.expired())

   {

       cout << "Expired" << endl;

   }

   else

   {

       cout << a.lock()->X << endl;

   }



   shared_ptr<A> a1 = make_shared<A>(13);

   weak_ptr<A> a2 = a1;

   cout << a1.use_count() << endl;

    cout << a2.lock()->X << endl;

    shared_ptr<A> a3 = a2.lock();

    cout << a1.use_count() << endl;



    return 0;

}