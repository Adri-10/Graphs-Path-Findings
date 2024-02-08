#include<stdio.h>
#include<algorithm>
#include <cstdlib>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
    int l,n,cutP[10],arr[10][10];
    scanf("%d %d",&l,&n);
    for(int i=1; i<=n; i++)
    {
        cin>>cutP[i];
    }
    for(int i=0;i<n;i++)
    {
           arr[0][i]=0;

    }
       for(int i=1;i<=n-1;i++){
           for(int j=1;j<=l;j++){
               if( cutP[i]>j ){
                   arr[i][j]=arr[i-1][j];
               }
               else{
          arr[i][j]=std::max( arr[i-1][j] , arr[i][abs(j-cutP[i]) ]  );
                   }
               }
           cout<<"The matrix is";
        for(int i=0;i<n;i++){
            for(int j=0;j<=l;j++){
               cout<<arr[i][j]<<" ";
            }
          cout<<endl;
        }
   cout<<"Total cost is "<<arr[n-1][1];
    }
}
