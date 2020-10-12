/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

//CODE

class Solution {
public:
    
    
    void findconnected(vector<vector<char>>& grid,int i,int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || i==m || j <0 || j==n || grid[i][j]=='0')
            return ;
        grid[i][j] = '0';
        findconnected(grid,i-1,j);
        findconnected(grid,i+1,j);
        findconnected(grid,i,j-1);
        findconnected(grid,i,j+1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int numisland = 0;
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1'){
                    numisland++;
                    findconnected(grid,i,j);
                }
                
            }
        }
        return numisland;
        
    }
};