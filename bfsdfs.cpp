#include <bits/stdc++.h>
#include <map>
#include <list>
#include <cstring>
#include <iostream>

using namespace std;

template<typename T >
class GraphForBFSSearch{

map<T,list<T> > mp;

public:
    void AddData(string x,string y){

    mp[x].push_back(y);
    mp[y].push_back(x);

    }

    void SeeData(){

    cout<<"The list contains: "<<endl;

    for(auto mp1: mp ){

    string x=mp1.first;
        list<T> l=mp1.second;

        cout<<"vertex: "<<mp1.first<<" -> ";

        for(string j: l){

            cout<<j<<" ";

        }

        cout<<endl;

    }

    }

    void BFS(T src){

     map<T,string> visited;
     queue<T> q;

map<T,bool> detect;

     q.push(src);

     detect[src]=true;

     while(!q.empty() ){

        T node=q.front();
        q.pop();

        cout<<node<<" ";

        for(string nbr:mp[node] ){

bool b=detect[nbr];

        if(!b ){

            q.push(nbr);
            detect[nbr]=true;

        }

        }

     }

    }

    void DFSHelper(T source,map<T,bool> &m ){

    cout<<source<<" ";

    m[source]=true;

    for(string nbr: mp[source]){

        if(!m[nbr]){

            DFSHelper(nbr,m);

        }

    }

    }

    void DFS(T source){

    map<T,bool> m;

  for(auto p: mp){

   T node=p.first;

   m[node]=false;

  }

  DFSHelper(source,m);

    }

};

int main(){

GraphForBFSSearch<string> graphForBFSSearch;

graphForBFSSearch.AddData("A","B");
graphForBFSSearch.AddData("B","C");
graphForBFSSearch.AddData("C","D");
graphForBFSSearch.AddData("D","A");
graphForBFSSearch.AddData("D","B");
graphForBFSSearch.AddData("C","A");
graphForBFSSearch.AddData("F","A");
graphForBFSSearch.AddData("F","B");
graphForBFSSearch.AddData("F","C");
graphForBFSSearch.AddData("F","E");
graphForBFSSearch.AddData("F","D");
graphForBFSSearch.AddData("G","A");
graphForBFSSearch.AddData("G","B");
graphForBFSSearch.AddData("G","C");
graphForBFSSearch.AddData("G","E");
graphForBFSSearch.AddData("G","D");
graphForBFSSearch.AddData("H","A");
graphForBFSSearch.AddData("H","B");
graphForBFSSearch.AddData("H","C");
graphForBFSSearch.AddData("H","E");
graphForBFSSearch.AddData("H","D");

graphForBFSSearch.SeeData();

cout<<"The BFS traversal is: ";

graphForBFSSearch.BFS("B");

cout<<endl<<"The DFS traversal is: ";

graphForBFSSearch.DFS("H");

}

