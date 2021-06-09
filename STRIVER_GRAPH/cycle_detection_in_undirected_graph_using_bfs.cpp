/*

cycle detection in undirected graph using bfs

*/


//CODE


#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int s, int n, vector<int>& visited, vector<int> adj[])
{
    queue<pair<int,int>> q;  // first is node, second is parent
 
    visited[s] = 1;

    q.push({s,-1});

    while(!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                visited[it] = 1;
                q.push({it,node});
            }

            else if(par != it)   //except parent if it meets any of the visited node then cycle is detected
                return true;
        }

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
        	if(checkcycle(i,n,visited,adj))
            		return 1;
    	}




	return 0;


}


//Time complexity is O(N+E)
//Space complexity is O(N+E) i.e adj list + O(N) i.e queue + O(N) i.e visited array
