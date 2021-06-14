/*

dijkstra's algo . shortest path in undirected graph

*/



//CODE


#include<bits/stdc++.h>
using namespace std;




int main()
{
	int m,n;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;

	cout<<"Enter no of edges"<<endl;
	cin>>m;

	vector<pair<int,int>> adj[n+1]; //n+1 size because of 1 based indexing

	//building a graph
	for(int i = 0 ; i < m ; i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;  //u means from vertex and v means to vertex (from u to v) and wt is the edge weight

		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});   //if directed graph then ignore this
	}

	int source;
	cout<<"Enter source"<<endl;
	cin>>source;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;  //pq of minh type  pair(dist,node)

	vector<int> distance(n+1,INT_MAX);

	distance[source] = 0;
	minh.push({0,source});

	while(!minh.empty())
    {
        int dist = minh.top().first;
        int node = minh.top().second;
        minh.pop();

        for(auto it : adj[node])
        {
            int nextnode = it.first;
            int nextdist = it.second;

            if(distance[nextnode] > dist + nextdist)
            {
                distance[nextnode] = dist + nextdist;
                minh.push({distance[nextnode], nextnode});
            }


        }
    }

    for(int i = 1; i <= n ; i++)
        cout<<source<<" : "<<i<<" = "<<distance[i]<<endl;






	return 0;


}
