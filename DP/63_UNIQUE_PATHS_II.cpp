/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

*/


//CODE

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size();
        int memo[m+1][n+1];
        for(int i = 0; i < m+1;i++)
        {
            for(int j = 0 ; j < n+1; j++)
                memo[i][j] = 0;
        }
        memo[0][1] = 1;
        for(int i = 1; i < m+1; i++)
        {
            for(int j  = 1; j  <n+1; j++)
            {
                if( obstacleGrid[i-1][j-1] != 1)
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        return memo[m][n];
    }
};