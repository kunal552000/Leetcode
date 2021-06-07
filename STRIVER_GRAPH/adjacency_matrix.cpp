//adjacency matrix representation

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;
	
	cout<<"Enter no of edges"<<endl;
	cin>>m;
	
	int adj[n+1][n+1] = {0}; //n+1 size because of 1 based indexing
	
	for(int i = 0 ; i < m ; i++)
	{
		int u,v;
		cin>>u>>v;  //u means from vertex and v means to vertex (from u to v)
		
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	
	
	return 0;
	
	
}