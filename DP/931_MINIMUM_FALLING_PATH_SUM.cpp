/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or 
diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), 
or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100


*/


//CODE



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int memo[m][n];
        
        int k = 0;
        
        for(int j = 0; j < n ; j++)
            memo[k][j] = matrix[k][j];
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
               int a,b,c;
                a = INT_MAX;
                b = INT_MAX;
                c = INT_MAX;
                
                a = memo[i-1][j] + matrix[i][j];
                
                if(j-1 >= 0)
                    b = memo[i-1][j-1] + matrix[i][j];
                
                if(j+1 < n)
                    c = memo[i-1][j+1] + matrix[i][j];
                
                memo[i][j] = min(a,min(b,c));
            }
        }
        
        int row = m-1;
        int res = INT_MAX;
        
        for(int i = 0;i < n; i++)
        {
            if(memo[row][i] < res)
                res = memo[row][i];
        }
        
        return res;
        
    
        
    }
};
