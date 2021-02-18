#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
using namespace std;
int main() {
vector<string> vs1 = { "Bob", "Steve", "Joe", "Alex", "William" }; 
vector<string> vs2 = { "Jane", "Sally", "Allison", "Pamela", "Emily" };
sort(vs1.begin(), vs1.end()); 
sort(vs2.begin(), vs2.end()); 
vector<string> vs3(vs1.size() + vs2.size()); 
merge(vs1.begin(), vs1.end(), vs2.begin(), vs2.end(), vs3.begin()); 
cout << "Result of Merge:\n";
for (const string& s : vs3) { 
cout << s << " "; 
} 
cout << "\n"; 

inplace_merge(vs1.begin(),vs1.begin()+3, vs1.end());
cout << "Result of inplace_merge:\n";
for (const string& s : vs1) { 
cout << s << " "; 
} 
cout << "\n"; 

vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19 }; 
vector<int> v2 = { 5, 7, 11 }; 
sort(v1.begin(), v1.end()); 
sort(v2.begin(), v2.end()); 
bool does_include = includes(v1.begin(), v1.end(), v2.begin(), v2.end());
cout << "include result:"<< boolalpha << does_include << "\n"; 
return 0;
}