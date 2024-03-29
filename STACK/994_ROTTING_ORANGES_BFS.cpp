/*


You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/


//CODE


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 0)
            return 0;
        
        int time = 0;
        int total = 0;
        int verify = 0;
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                    total++;
                
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty())
        {
            int size = q.size();
            verify = verify + size;
            
            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) 
                    {
                
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                        
                }
            }
            if(!q.empty())
                    time++;
        }
        
        if(total == verify)
            return time;
        
        return -1;
        
        
    }
};