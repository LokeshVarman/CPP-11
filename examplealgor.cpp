#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int mod5(int v)
{
return v%5;
}
 
int main() { 

vector<int> v = {5,25,4,7,89,57,897,334};
cout << "Before Transform:\n";
for(auto i: v)
{
cout << i << ' ';
}
transform(v.begin(),v.end(),v.begin(),mod5);
cout << "\nAfter transform, saving mod5 output in vector:\n ";
for(auto i: v)
{
cout << i << ' ';
}

list<string> ls = { "one", "elbow", "blue", "toad", "galaxy", "socks" };
    //copy list of strings to a deque of strings
deque<string> ds;
copy(ls.begin(), ls.end(), back_inserter(ds));
cout  << "\nAfter copying ls list Contents to deque 'ds' using back_inserter: \n";
for (const auto& str : ds) {
    cout  << str <<  " ";
}
cout  << "\n\n";

//move deque of strings to another list of strings
list<string> ls2(make_move_iterator(ds.begin()), make_move_iterator(ds.end()));
cout  << "After using the make_move_iterator of ds to ls2, Contents of 'ds': \n";
for (const auto& str : ds) {
    cout  << str <<  " ";
}
cout  << "\n\n";

cout  << "After using the make_move_iterator, Contents of 'ls2': \n";
for (const auto& str : ls2) {
   cout  << str  << " ";
}
cout << "\n\n";

vector<int> v1 = { 0, 1, 2, 3, 0, 844, 34, 0, 22, 11, 2, 0 }; 
cout << "Befor replace:\n";
for (int i : v1) { 
          cout <<  i <<  " "; 
    } 
    replace(v1.begin(), v1.end(), 0, 1); 
cout << "\nAfter replacing 0 with 1:\n";
    for (int i : v1) { 
          cout <<  i <<  " "; 
    } 
    cout<< "\n"; 

 replace_if(v1.begin(), v1.end(), [](int i) { return (i % 2) == 0; }, -1); 
 cout << "After replacing using the replace_if,the value will be -1, if element was even:\n";
    for (int i : v1) { 
         cout << i << " "; 
    } 
    cout << "\n"; 
return 0;

}