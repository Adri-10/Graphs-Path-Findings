#include <bits/stdc++.h>
using namespace std;
#define infinity 9999

int main()
{
    int sum,n;
    cout<<"Enter total amount: ";
    cin>>sum;
    cout<<"Enter number of coins: ";
    cin>>n;
    int a[n+1];
    a[0]=0;
    cout<<"Enter values of "<<n<<" no coins: ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=infinity;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i]<=j && (1+dp[i][j-a[i]])<dp[i-1][j])
            {
                dp[i][j]=1+dp[i][j-a[i]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
     cout<<"The matrix is: "<<endl;

    for(int i=0; i<=n; i++)
    {

        for(int j=0; j<=sum; j++)
        {
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;

    }
    cout<<"\nMinimum number of coins required: "<<dp[n][sum]<<endl;
    int i=n;
    int j=sum;
    cout<<"Selected coins: ";
    for(int k=0;k<dp[n][sum];k++)
    {
        while(dp[i][j]==dp[i-1][j] && i>0)
        {
            i--;
        }
        j=j-a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
