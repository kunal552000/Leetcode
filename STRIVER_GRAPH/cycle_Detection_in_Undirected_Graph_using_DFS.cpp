/*

cycle detection in undirected graph using dfs

*/


//CODE


#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int node, int parent, vector<int>& visited, vector<int> adj[])
{
    visited[node] = 1;

    for(auto it : adj[node])
    {
        
        if(visited[it] == 0)
        {
            if(checkcycle(it,node,visited,adj))
                return true;
        }
        
        else if(it != parent)
            return true;

    }

    return false;

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

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {


            if(checkcycle(i,-1,visited,adj))
                return 1;

        }
    }




	return 0;


}

//Time Complexity is O(N+E)

//Space Complexity is O(N+E) i.e adj list + O(N) i.e visited array + O(N) i.e auxilary space
