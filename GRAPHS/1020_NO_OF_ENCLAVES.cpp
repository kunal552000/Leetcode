/*

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/


//CODE


class Solution {
public:
    
    
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return ;
        
        grid[i][j] = 0;
        
        dfs(grid,i+1,j,m,n);
        dfs(grid,i-1,j,m,n);
        dfs(grid,i,j+1,m,n);
        dfs(grid,i,j-1,m,n);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        
        if(m == 0)
            return 0;
        
        int n = grid[0].size();
        
        int res  = 0;
        
        for(int i = 0; i < m; i++)
        {
            if(grid[i][0] == 1)
                dfs(grid,i,0,m,n);
            
            if(grid[i][n-1] == 1)
                dfs(grid,i,n-1,m,n);
        }
        
        for(int j = 0; j < n ; j++)
        {
            if(grid[0][j] == 1)
                dfs(grid,0,j,m,n);
            
            if(grid[m-1][j] == 1)
                dfs(grid,m-1,j,m,n);
        }
        
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(grid[i][j] == 1)
                    res++;
            }
        }
        
        return res;
        
        
        
        
        
        
    }
};