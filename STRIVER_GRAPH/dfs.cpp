/*

dfs traversal of a graph

*/


//CODE


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, vector<int>adj[])
{
	cout<<node<<" ";

	visited[node] = 1;

	for(auto it : adj[node])
    {
        if(visited[it] == 0)
        {
            dfs(it,visited,adj);  //recursive dfs calls
        }
    }

}

int main()
{
	int m,n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;

	cout<<"Enter no of edges"<<endl;
	cin>>m;

	vector<int> adj[n+1]; //n+1 size because of 1 based indexing

	//building a graph
	for(int i = 0 ; i < m ; i++)
	{
		int u,v;
		cin>>u>>v;  //u means from vertex and v means to vertex (from u to v)

		adj[u].push_back(v);
		adj[v].push_back(u);   //if directed graph then ignore this
	}

	vector<int> visited(n+1, 0);  //visited array

	for(int i = 1; i <= n ; i++)
    	{
        	if(visited[i] == 0)
        	{
            		dfs(i,visited,adj); //call dfs
        	}
    	}


	return 0;


}


//Time complexity is O(N+E) as every node is visited once and dfs is called only for unvisited nodes.

//Space complexity is O(N+E) i.e adj list + O(N) i.e visited array 
