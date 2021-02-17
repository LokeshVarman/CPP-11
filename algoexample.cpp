#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

void output_val(int v) { 
      cout << v << " "; 
}
int main() { 
vector<int> v = { 42, 128, 995, 443, 9000, 3, 4, 5 }; 
cout << "for loop with iterator: \n"; 
for (auto itr = v.begin(); itr != v.end(); ++itr) { 
cout << *itr << " "; 
} 
          
cout << "\n\n"; 

cout << "for_each loop with a function: \n"; 
for_each(v.begin(), v.end(), output_val); 
cout << "\n\n"; 

cout << "for each loop with lambda expression: \n";
for_each(v.begin(), v.end(), [](int v) {
cout << v << " "; 
}); 

cout << "\n"; 
return 0; 
}