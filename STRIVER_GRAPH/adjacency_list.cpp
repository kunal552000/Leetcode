// adjacency list

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;
	
	cout<<"Enter no of edges"<<endl;
	cin>>m;
	
	vector<int> adj[n+1]; //n+1 size because of 1 based indexing
	
	for(int i = 0 ; i < m ; i++)
	{
		int u,v;
		cin>>u>>v;  //u means from vertex and v means to vertex (from u to v)
		
		adj[u].push_back(v);
		adj[v].push_back(u);   //if directed graph then ignore this
	}
	
	
	return 0;
	
	
}