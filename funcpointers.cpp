
void add(int a, int b);
void mutliply(int a, int b);
void divide(int a, int b);
void subtract(int a, int b);
void remaindar(int a, int b);
typedef void (*fp) (int, int);void operate(fp operations[] , int countofoperations,int a, int b)
{
if((countofoperations>0) && countofoperations<5)
{
for(int i=0;i<countofoperations; i++)
{}
operations[i](a,b);
}
}​​
else
{​​
cout << "Something wrong in the sequence";
}
}​​
int main()
{​​
cout << "Enter two numbers to perform operation:";
int a, b;
cin>>a,b;
cout <<"1. Add\n 2. Add and Subtract\n 3. Add, subtract and Mutliply\n 4. Add, subtract, mulltiply and divide \n 5. All");
cout << "Enter how many operations:";
int n;
cin>>n;
fp operations[]={​​add,subtract,mulltiply,divide,remaindar}​​;
operate(operations,n,a,b);
return 0;
}​​