/*

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.


*/


//CODE


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        
        int n = matrix[0].size();
        
        int memo[m][n];
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(i == 0 || j == 0)
                {
                    if(matrix[i][j] == '0')
                        memo[i][j] = 0;
                    
                    else
                        memo[i][j] = 1;
                }
            }
        }
        
        for(int i = 1; i < m ; i++)
        {
            for(int j = 1; j < n ; j++)
            {
                if(matrix[i][j] == '0')
                    memo[i][j] = 0;
                
                else
                    memo[i][j] = 1 + min(memo[i-1][j-1],min(memo[i-1][j],memo[i][j-1]));
            }
        }
        
        int res = 0;
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(memo[i][j] > res)
                    res = memo[i][j];
            }
        }
        
        return res*res;  //res is the side of square and area is side*side
        
    }
};