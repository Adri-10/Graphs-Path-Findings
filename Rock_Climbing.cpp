#include <bits/stdc++.h>
#include <list>
using namespace std;

int min(int a, int b,int c)
{
    if((a<=b) && (a<=c))
    {
        return a;
    }
    else if((b<=c)&&(b<=a))
    {
        return b;
    }
    else if((c<=a) && (c<=b))
    {
        return c;
    }
}

int main()
{

    int i,j,width=5,height=4;

    int c[5][6];

    for( i=1; i<=4; i++)
    {
        for( j=1; j<=5; j++)
        {
            cin>>c[i][j];
        }
    }

    int mat[height+1][width+2];

    for(j=1; j<=width; j++)
    {

        mat[0][j]=0;

    }

    for( i=0; i<=height; i++)
    {

        mat[i][0]=999;

    }
    for( i=0; i<=height; i++)
    {
        mat[i][6]=999;

    }
    for( i=1; i<=4; i++)
    {
        for( j=1; j<=5; j++)
        {
            int minimum=min(mat[i-1][j-1],mat[i-1][j],mat[i-1][j+1]);
            mat[i][j]= c[i][j]+minimum;

        }
    }
    cout<<"The matrix is: "<<endl;
    for(int i=0; i<=4; i++)
    {

        for(int j=0; j<=6; j++)
        {
            cout<<mat[i][j]<<"   ";
        }
        cout<<endl;
    }
    list<int> rock;
    int k=0;
    for(int i=1; i<=width; i++)
    {

        rock.push_back(mat[4][i]);
        k++;
    }
    rock.sort();
    cout<<"So the best path to the top is : "<<rock.front() ;
}
//2 8 9 5 8 4 4 6 2 3 5 7 5 6 1 3 2 5 4 8
//3 2 5 4 8 5 7 5 6 1 4 4 6 2 3 2 8 9 5 8
