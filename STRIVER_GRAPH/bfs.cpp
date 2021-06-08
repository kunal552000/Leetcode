/*

bfs traversal of a graph

*/

//CODE


#include<bits/stdc++.h>
using namespace std;

void bfs(int V, vector<int>adj[])
{
	vector<int> vis(V+1,0); //visited array

	for(int i = 1; i<=V; i++)
	{
		if(vis[i] == 0)
		{
			queue<int> q;
			q.push(i);
			vis[i] = 1;

			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				cout<<node<<" ";

				for(auto it : adj[node])
				{
					if(vis[it] == 0)
					{
						q.push(it);
						vis[it] = 1;
					}
				}
			}
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

	//calling bfs by taking no of nodes and the adj list as parameters
	bfs(n, adj);


	return 0;


}
