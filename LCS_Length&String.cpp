#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
int lcs(char *X,char *Y,int m,int n)
{
    if (m==0||n==0)
        return 0;
    if (X[m-1]==Y[n-1])
        return 1+lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1),lcs(X, Y, m-1, n));
}

void Lcs(char *X,char *Y,int m,int n)
{
    int c[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i==0||j==0)
                c[i][j]=0;
            else if (X[i-1]==Y[j-1])
                c[i][j]=c[i-1][j-1] + 1;
            else
                c[i][j]=max(c[i-1][j], c[i][j-1]);
        }
    }
    int index=c[m][n];
    char lcs[index+1];
    lcs[index]='\0';
    int i=m, j=n;
    while (i>0&&j>0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1]=X[i-1];
            i--;
            j--;
            index--;
        }
        else if (c[i-1][j]>c[i][j-1])
            i--;
        else
            j--;
    }
    cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
void findString(char x[],char y[],int lenX,int lenY)
{
    int arr[lenX+1][lenY+1];
    int i,j;
    for (i=0; i<=lenY; ++i)
    {
        arr[0][i]=0;
    }
    for (i=0; i<=lenX; ++i)
    {
        arr[i][0]=0;
    }

    for(i=1; i<=lenX; ++i)
    {
        for(j=1; j<=lenY ; ++j)
        {
            if(x[i-1]==y[j-1])
            {
                arr[i][j]=arr[i-1][j-1] + 1;
            }
            else
            {
                if(arr[i-1][j]>=arr[i][j-1])
                    arr[i][j]=arr[i-1][j];
                else
                    arr[i][j]=arr[i][j-1];
            }
        }
    }
    for (i=0; i<=lenX; ++i)
    {
        for (j=0; j<=lenY; ++j)
        {
            cout<<"     "<<arr[i][j];
        }
        cout<<"\n";
    }
}
int main()
{
    char x[20],y[20];
    cout<<"enter two string:\n";
    cin>>x>>y;
    int m=strlen(x);
    int n=strlen(y);
    findString(x,y, m, n);
    cout<<"\n";
    cout<<"\nmaximum length: "<<lcs( x,y, m, n )<<endl;
    cout<<"\n";
    Lcs(x,y, m, n);
    cout<<"\n";
    return 0;
 //abcbdab bdcaba
}
