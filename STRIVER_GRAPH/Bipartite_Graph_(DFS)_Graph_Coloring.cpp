/*

bipartite graph dfs

*/


//CODE


#include<bits/stdc++.h>
using namespace std;

bool bipartite(int node , vector<int>& color, vector<int> adj[])
{
    for(auto it : adj[node])
    {
        if(color[it] == -1)
        {
            color[it] = 1 - color[node];
            if(!bipartite(it,color,adj))
                return false;
        }
        
        else if(color[it] == color[node])
            return false;
    }
    return true;

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

	vector<int> color(n+1, -1);  //color array

    for(int i = 1; i <= n; i++)
    {
        if(color[i] == -1)
        {
            color[i] = 1;


            if(!bipartite(i,color,adj))
                return 0;
        }
    }




	return 1;


}

//Time Complexity O(N+E)
//Space Complexity O(N+E) i.e adj list + O(N) i.e color array + O(N) i.e auxilary space for recursion.