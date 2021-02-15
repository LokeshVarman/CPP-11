#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
   try{
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0\n");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1\n");
    }
   }
   catch(invalid_argument pi){
       cout<<pi.what();
        
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    //return -1; // will never happen
}

void process_input(int n) {
    int d = largest_proper_divisor(n);
    if (n>1){
        cout << "result=" << d << endl;
    }
        cout<<"returning control flow to caller"<<endl;
    
}


int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
