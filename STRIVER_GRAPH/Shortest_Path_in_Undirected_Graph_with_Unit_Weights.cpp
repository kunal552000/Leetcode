/*

given an undirected graph with unit weights and a source. Find the shortest distance from source to all nodes

*/

//CODE


#include<bits/stdc++.h>
using namespace std;

void bfs(int n, int source, vector<int> adj[])
{
    vector<int> dist(n,INT_MAX);
    queue<int> q;

    q.push(source);
    dist[source] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i < n ; i++)
        cout<<source<<" : "<<i<<" = "<<dist[i]<<endl;

}

int main()
{
	int m,n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;

	cout<<"Enter no of edges"<<endl;
	cin>>m;

	vector<int> adj[n]; //n+1 size because of 1 based indexing

	//building a graph
	for(int i = 0 ; i < m ; i++)
	{
		int u,v;
		cin>>u>>v;  //u means from vertex and v means to vertex (from u to v)

		adj[u].push_back(v);
		adj[v].push_back(u);   //if directed graph then ignore this
	}

	int source;
	cout<<"Enter source"<<endl;
	cin>>source;

	bfs(n,source,adj);






	return 0;


}
