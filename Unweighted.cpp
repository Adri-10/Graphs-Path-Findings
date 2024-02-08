#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
#define NULL_VALUE -999999
#define INFINITY 999999

using namespace std;

void formConnection(int graph[100][100],int u,int v){
    graph[u][v]=1;
    graph[v][u]=1;
}

int getMinDist(int matrix[100][100],int u,int v,int nVertices){
    queue<int> q;
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return NULL_VALUE;
    int minDist[nVertices];
    //Queue trav;
    for(int i=0;i<nVertices;i++){
        minDist[i]=INFINITY;
    }
    minDist[u]=0;
    q.push(u);
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=0;i<nVertices;i++){
            int k=NULL_VALUE;
            if(matrix[p][i]!=0){
                k=i;
            }
            if(k!=NULL_VALUE){
                if(minDist[k]>(minDist[p]+matrix[p][k])){
                    minDist[k]=minDist[p]+matrix[p][k];
                    q.push(k);
                }
            }
        }
    }
    return minDist[v];
}

int main()
{
        int n,e,u,v,i,j;
        int graph[100][100];
        cout<<"enter number of house (n): ";
        cin>>n;
        cout<<"enter number of roads (r): ";
        cin>>e;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                graph[i][j]=0;
            }
        }
        cout<<"enter roads:\n";
        for(i=0; i<e; i++)
        {
            cin>>u>>v;
            formConnection(graph,u,v);
        }
        cout<<endl;
        int s1,s2,s3,tr;
        cout<<"Enter mouse house 1: ";
        cin>>s1;
        cout<<"Enter mouse house 2: ";
        cin>>s2;
        cout<<"Enter mouse house 3: ";
        cin>>s3;
        cout<<"Enter treasure/cheese house: ";
        cin>>tr;
        int d1=getMinDist(graph,s1,tr,n);
        int d2=getMinDist(graph,s2,tr,n);
        int d3=getMinDist(graph,s3,tr,n);
        int ans;
        if(d1<=d2 && d1<=d3){
            ans=s1;
        }
        else if(d2<=d1 && d2<=d3){
            ans=s2;
        }
        else if(d3<=d1 && d3<=d2){
            ans=s3;
        }
        cout<<"\nMouse in house "<<ans<<" will reach cheese first"<<endl;
}
/*  6
 8
0 4
2 5
0 1
3 2
0 3
2 1
0 5
4 5
0
1
4
5
 */
