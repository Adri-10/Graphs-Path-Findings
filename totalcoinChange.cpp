#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[]= {1,2,3};
    int sum=5;
    int n=sizeof(a)/sizeof( a[0] );
    int dp[10][10];
    dp[0][0]=1;
    for(int i=1; i<=sum; i++)
    {
        dp[0][i]=0;

    }
    for(int i=1; i<=n; i++)
    {
        dp[i][0]=1;
    }
    for(int i=1; i<=n; i++)
    {

        for(int j=1; j<=sum; j++)
        {
            if(a[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];

            }
            else
            {
                dp[i][j]= dp[i-1][j] + dp[i][j-a[i-1]];
            }
        }
    }

    cout<<"The array is: "<<endl;

    for(int i=0; i<=n; i++)
    {

        for(int j=0; j<=sum; j++)
        {
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;

    }
    cout<<"Total way: "<<dp[n][sum]<<endl ;

}
