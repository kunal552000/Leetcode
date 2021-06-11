/*

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

*/


//CODE

class Solution
{
    public:
    
    bool check(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[])
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
            {
                if(check(it,vis,dfsvis,adj))
                    return true;
            }
            
            else if(dfsvis[it] == 1)
                return true ;
        }
        
        dfsvis[node] = 0;
        return false;
    }
    
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	
	   	vector<int> vis(V,0);
	   	vector<int> dfsvis(V,0);
	   	
	   	for(int i = 0; i < V; i++)
	   	{
	   	    if(vis[i] == 0)
	   	    {
	   	        if(check(i,vis,dfsvis,adj))
	   	        return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};