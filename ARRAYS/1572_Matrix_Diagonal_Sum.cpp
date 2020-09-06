/*

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

Example 1:


Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5
 

Constraints:

n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100

*/

//CODE

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int sum1 = 0;
        int sum2 = 0;
        int i,j;
        if(rows%2==0)
        {
            for(i=0;i<rows;i++)
                for(j=0;j<rows;j++){
                    if(i==j)
                    {
                        sum1 = sum1 + mat[i][j];
                    }
                    if(i+j== rows-1){
                        sum2 = sum2 + mat[i][j];
                    }
                }
            
            return sum1+sum2;
        }
        else{
            for(i=0;i<rows;i++)
                for(j=0;j<rows;j++){
                    if(i == j){
                        sum1 = sum1 + mat[i][j];
                    }
                    if(i+j == rows-1){
                        sum2 = sum2 + mat[i][j];
                    }
                        
                    
                }
            return sum1+sum2-mat[rows/2][rows/2];
        }
        
    }
};