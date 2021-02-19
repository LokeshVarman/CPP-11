#include <algorithm> 
#include <iostream> 

using namespace std; 

void show(int a[], int arraysize) 
{ 
	for (int i = 0; i < arraysize; ++i) 
		cout << a[i] << ","; 
} 

int main() 
{ 
	int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
	int asize = sizeof(a) / sizeof(a[0]); 
	cout << "\nThe array is : \n"; 
	show(a, asize); 


	cout << "\n we are searching for 6 in the array, so sort first"; 
	//sort
	sort(a, a + asize); 
	cout << "\n\nafter sorting is : \n"; 
	show(a, asize); 
	cout << "\n\ndoing binary search"; 
	//binary search
	if (binary_search(a, a + 10, 6)) 
		cout << "\nElement found in the array"; 
	else
		cout << "\nElement not found in the array"; 

	cout << "\n\n searching for 10"; 
	if (binary_search(a, a + 10, 10)) 
		cout << "\nElement found in the array"; 
	else
		cout << "\nElement not found in the array"; 

	return 0; 
}
