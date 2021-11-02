/*

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.

*/


//CODE


class Solution {
public:
    int res  = 0,empty = 1;
    
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int count)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
            return;
        
        if(grid[i][j] == 2)
        {
            if(count == empty)
                res++;
            
            return;
        }
        
        grid[i][j] = -1;
        
        dfs(grid,i+1,j,m,n,count+1);
        dfs(grid,i-1,j,m,n,count+1);
        dfs(grid,i,j+1,m,n,count+1);
        dfs(grid,i,j-1,m,n,count+1);
        
        grid[i][j] = 0;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int sx = 0;
        int sy = 0;
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j  < n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                
                else if(grid[i][j] == 0)
                    empty++;
            }
        }
        
        dfs(grid,sx,sy,m,n,0);
        return res;
        
    }
};