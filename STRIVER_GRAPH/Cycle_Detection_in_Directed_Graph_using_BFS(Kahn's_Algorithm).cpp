/*

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

*/


//CODE


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	queue<int> q;
    		vector<int> indeg(V,0);

    		for(int i = 0; i < V ; i++)
    		{
        		for(auto it : adj[i])
            		    indeg[it]++;
    		}

   		for(int i = 0; i < V ; i++)
    		{
        		if(indeg[i] == 0)
            		    q.push(i);
    		}

    		int cnt = 0;

    		while(!q.empty())
    		{
        		int node = q.front();
        		q.pop();
        		cnt++;

        		for(auto it : adj[node])
        		{
            			indeg[it]--;

            			if(indeg[it] == 0)
                		   q.push(it);
        		}	
    		}

    		if(cnt == V)
        	return false;

    		return true;
	}
};