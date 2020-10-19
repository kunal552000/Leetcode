/*

There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.


*/


//CODE


class Solution {
public:

//TOPOLOGICAL SORT AND ORDERING
    void dfs(vector<int> adj[],int source,int numCourses, unordered_set<int> &set,stack<int> &s)
    {
        set.insert(source);
        for(int i =0;i<adj[source].size();i++)
        {
            if(set.find(adj[source][i]) == set.end())
            {
                dfs(adj,adj[source][i],numCourses,set,s);
            }
        }
        s.push(source);
    }

//CYCLE DETECTION
     bool iscycle(vector<int> adj[], vector<int> &vis, int present)
    {
       
        if(vis[present] == 1)
            return true;
        if(vis[present] == 0)
        {
            vis[present] = 1;
            for(auto i : adj[present])
            {
                if(iscycle(adj,vis,i))
                    return true;
            }
        }
        vis[present] = 2;
        return false;
    }


//GIVEN FUNCTION
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];
        vector<int> res;
        //vector<int> ans;
        for(auto i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);  //CONVERSION INTO ADJ LIST
            
        }
        vector<int> vis(numCourses,0);
        for(int j =0;j<numCourses;j++)
        {
            if(iscycle(adj,vis,j))
            {
             return res;
            }
        }
        unordered_set<int> set;
                stack<int> s;
                for(int i =0;i<numCourses;i++)
                {
                    if(set.find(i)==set.end())
                    {
                        dfs(adj,i,numCourses,set,s); 
                    }
                }
                while(!s.empty())
                {
                    res.push_back(s.top());   //STORING THE ORDER
                    s.pop();
                }
                return res;
    }
};