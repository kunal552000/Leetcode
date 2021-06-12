/*

Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.

*/


//CODE


class Solution
{
	public:
	
	void findtopo(int node, stack<int>& s, vector<int>& vis, vector<int> adj[])
	{
	    vis[node] = 1;
	    
	    for(auto it : adj[node])
	    {
	        if(vis[it] == 0)
	        {
	            findtopo(it,s,vis,adj);
	        }
	    }
	    
	    s.push(node);
	}
	
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> s;
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(vis[i] == 0)
	        {
	            findtopo(i,s,vis,adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};