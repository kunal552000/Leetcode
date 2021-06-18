/*

Kosaraju algo for strongly connected compnonents

*/


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(vis[it] == 0)
        {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}


void revDfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for(auto it: transpose[node])
    {
        if(vis[it] == 0)
        {
            revDfs(it, vis, transpose);
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

	vector<int> adj[n]; //n+1 size because of 1 based indexing

	//building a graph
	for(int i = 0 ; i < m ; i++)
	{
		int u,v;
		cin>>u>>v;  //u means from vertex and v means to vertex (from u to v) and wt is the edge weight

		adj[u].push_back(v);
		//adj[v].push_back({u,wt});   //if directed graph then ignore this
	}



	stack<int> st;
	vector<int> vis(n, 0);

	for(int i = 0;i<n;i++)
    {
	    if(vis[i] == 0)
	    {
	        dfs(i, st, vis, adj);
	    }
	}

    vector<int> transpose[n];

    for(int i = 0;i<n;i++)
    {
	    vis[i] = 0;
	    for(auto it: adj[i])
	    {
	        transpose[it].push_back(i);
	    }
	}

	while(!st.empty())
    {
	    int node = st.top();
	    st.pop();
	    if(vis[node] == 0)
	    {
	        cout << "SCC: ";
	        revDfs(node, vis, transpose);
	        cout << endl;
	    }
	}





	return 0;


}
