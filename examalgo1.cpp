#include <iostream>
#include <algorithm>
#include <vector>
#include <string>



using namespace std;



bool IsOdd (int i) {
return ((i%2)==1);
}




int main() {
vector<int> v ={ 1, 2, 3, 2, 42, 128, 443, 7000,5 };
vector<int>::iterator itr = find(v.begin(), v.end(), 443);
while (itr != v.end()) {
cout << *itr << " ";
++itr;
}



auto it = find_if (v.begin(), v.end(), IsOdd);
cout << "\nThe first odd value is " << *it << '\n';



auto it1=find_if(++it,v.end(),IsOdd);
cout << "The next odd value is"<<*it1<<'\n';



int mycount = std::count (v.begin(), v.end(), 2);
std::cout << "2 appears " << mycount << " times.\n";




int mycount2 = std::count_if (v.begin(), v.end(), IsOdd);
std::cout << "Odd numbers in vector " << mycount2 << " times.\n";



bool b = any_of(v.begin(), v.end(), [](int a) { return a == 5; });
cout << boolalpha << b << "\n";
return 0;
}