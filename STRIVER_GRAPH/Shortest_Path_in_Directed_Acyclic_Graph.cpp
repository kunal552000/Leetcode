/*

given a DAG with weights and a source. Find the shortest distance from source to all nodes

*/


//code


#include<bits/stdc++.h>
using namespace std;


void findtopo(int node, vector<int>& vis, stack<int>& s, vector<pair<int,int>> adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(vis[it.first] == 0)
            findtopo(it.first,vis,s,adj);
    }

    s.push(node);
}

void shortest(int n, int source, vector<pair<int,int>> adj[])
{
    vector<int> vis(n,0);
    stack<int> s;

    for(int i = 0; i < n ; i++)
    {
        if(vis[i] == 0)
            findtopo(i,vis,s,adj);

    }

    vector<int> dist(n,INT_MAX);
    dist[source] = 0;

    while(!s.empty())
    {
        int node = s.top();
        s.pop();

        if(dist[node] != INT_MAX)
        {
            for(auto it : adj[node])
            {
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for(int i = 0; i < n ; i++)
    {
        if(dist[i] == INT_MAX)
            cout<<source<<" : "<<i<<" = "<<INT_MAX<<endl;
        else
            cout<<source<<" : "<<i<<" = "<<dist[i]<<endl;
    }

}

int main()
{
	int m,n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;

	cout<<"Enter no of edges"<<endl;
	cin>>m;

	vector<pair<int,int>> adj[n]; //n+1 size because of 1 based indexing

	//building a graph
	for(int i = 0 ; i < m ; i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;  //u means from vertex and v means to vertex (from u to v) and wt is the edge weight

		adj[u].push_back({v,wt});
		//adj[v].push_back(u);   //if directed graph then ignore this
	}

	int source;
	cout<<"Enter source"<<endl;
	cin>>source;

	shortest(n,source,adj);






	return 0;


}
