#include<iostream>
using namespace std;

int main()
{
    int n,total;
    cout<<"Enter total weight: ";
    cin>>total;
    cout<<"Enter number of items: ";
    cin>>n;
    int w[n+1],v[n+1];
    w[0]=0;
    v[0]=0;

    cout<<"Enter weights of "<<n<<" items: ";
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];
    }

    cout<<"Enter values of "<<n<<" items: ";
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }

    int p[n+1][total+1];
    for(int j=0; j<=total; j++)
    {
        p[0][j]=0;
    }
    for(int i=1; i<=n; i++)
    {
        p[i][0]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=total; j++)
        {
            if(w[i]<=j)
            {
                if((v[i]+p[i-1][j-w[i]])>p[i-1][j])
                {
                    p[i][j]=(v[i]+p[i-1][j-w[i]]);
                }
                else
                {
                    p[i][j]=p[i-1][j];
                }
            }
            else
            {
                p[i][j]=p[i-1][j];
            }
        }
    }
    cout<<"\nMaximum Profit : "<<p[n][total]<<endl;
    int m=total;
    cout<<"\n Chosen items: \n"<<endl;
    for(int i=n; i>0; i--)
    {
        if(p[i][m]!=p[i-1][m])
        {
            cout<<"Item no: "<<i<<"   Weight: "<<w[i]<<"  Value: "<<v[i]<<endl;
            m=m-w[i];
        }
    }
    cout<<"\n";
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=total; j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}
