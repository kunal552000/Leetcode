/*

Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.

*/


//CODE


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    queue<int> q;
	    vector<int> indeg(V,0);
	    
	    for(int i = 0 ; i < V; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indeg[it]++;
	        }
	    }
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(indeg[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indeg[it]--;
	            
	            if(indeg[it] == 0)
	            q.push(it);
	        }
	    }
	    
	    return ans;
	    
	    
	}
};