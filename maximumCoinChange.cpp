#include<bits/stdc++.h>
using namespace std;

int coinChange(int sum, int n, int *coin){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<coin[i-1])
                dp[i][j] = dp[i-1][j];
            if(j>=coin[i-1])
                dp[i][j] = dp[i-1][j] + dp[i][j-coin[i-1]];
        }
    }

    //Print the table
    cout<<endl<<"Dynamic Programming Table:"<<endl<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
              cout<<dp[i][j]<<"\t";
        cout<<endl;
    }

    return dp[n][sum];
}
int main(){
    int sum, coin[] = {1,2,3};
    int n = sizeof(coin)/sizeof(coin[0]);
    cout<<"Input a sum: ";cin>>sum;
    int total = coinChange(sum,n,coin);
    cout<<endl<<"Total possible combination: "<<total<<endl;
}

