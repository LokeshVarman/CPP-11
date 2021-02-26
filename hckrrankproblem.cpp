
#include<bits/stdc++.h>
using namespace std;
int minParts(vector<int>usedSpace,vector<int>totalSpace){
   int q;
   q=totalSpace.size();
   sort(usedSpace.begin(),usedSpace.end());
   sort(totalSpace.begin(),totalSpace.end());
   int used=accumulate(usedSpace.begin(),usedSpace.end(),0);
   int min=0;
   for(int i=q-1;i>=0;i--){
       if(used<=totalSpace[i]){
          min=min+1;
          break;
       }
       else{
          used=used-totalSpace[i];
          min=min+1;
       }
   }
   return min;
}

int main(){
   vector<int>usedSpace={3,2,1,3,1};
   vector<int>totalSpace={3,5,3,5,5};


   int m=minParts(usedSpace,totalSpace);
   cout<<m;

   return 0;
}
