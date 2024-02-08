#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n+1],list[n+1];
    arr[0]=-999;
    list[0]=0;
    cout<<"Enter "<<n<<" array elements: ";
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++)
    {
        int maxim=-1;
        for(int j=0; j<i; j++)
        {
            if(arr[j]<arr[i] && list[j]>maxim )
            {
                maxim=list[j];
                list[i]=1+maxim;
            }
        }
    }
    int max=-1;
    int l_index=-1;
    for(int i=0; i<=n; i++)
    {
        if(list[i]>max)
        {
            max=list[i];
            l_index=i;
        }
    }
    cout<<"\nLongest subsequence length is: "<<max<<endl;
    cout<<"\nThe Longest subsequence is: ";
    for(int i=1; i<=l_index; i++)
    {
        if(list[i]!=list[i+1])
        {
            cout<<arr[i]<<" ";
        }
    }
}
//11 0 9 2 5 3 7 11 8 10 13 6
