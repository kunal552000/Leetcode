/*

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.

*/


//CODE


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        //first row
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && i < n-1)
            {
                if(mat[0][i] > mat[0][i-1] && mat[0][i]  > mat[0][i+1] && mat[0][1] > mat[1][i])
                    return{0,i};
            }
            
            else if(i == 0)
            {
                if(mat[0][0] > mat[0][1] && mat[0][0] > mat[1][0])
                    return {0,0};
            }
            
            else if(i == n-1)
                if(mat[0][n-1] > mat[0][n-2] && mat[0][n-1] > mat[1][n-1])
                    return{0,n-1};
        }
        
        
        //last row
         for(int i = 0; i < n; i++)
        {
            if(i > 0 && i < n-1)
            {
                if(mat[m-1][i] > mat[m-1][i-1] && mat[m-1][i]  > mat[m-1][i+1] && mat[m-1][i] > mat[m-2][i])
                    return{m-1,i};
            }
            
            else if(i == 0)
            {
                if(mat[m-1][0] > mat[m-1][1] && mat[m-1][0] > mat[m-2][0])
                    return {m-1,0};
            }
            
            else if(i == n-1)
                if(mat[m-1][n-1] > mat[m-1][n-2] && mat[m-1][n-1] > mat[m-2][n-1])
                    return{m-1,n-1};
        }
        
        
        //middle rows
        
        for(int i = 1; i < m; i++)
        {
            if(mat[i][0] > mat[i][1] && mat[i][0] > mat[i+1][0] && mat[i][0] > mat[i-1][0])
                return{i,0};
            
            if(mat[i][n-1] > mat[i][n-2] && mat[i][n-1] > mat[i-1][n-1] && mat[i][n-1] > mat[i+1][n-1])
                return{i,n-1};
            
            int start = 1;
            int end = n-2;
            
            while(start <= end)
            {
                int mid = start + (end-start)/2;
                
                if(mat[i][mid] > mat[i][mid-1] && mat[i][mid] > mat[i][mid+1] &&
                 mat[i][mid] > mat[i-1][mid] && mat[i][mid] > mat[i+1][mid] )
                    return {i,mid};
                
                else if(mat[i][mid-1] > mat[i][mid])
                    end = mid-1;
                
                else
                    start = mid+1;
                
            }
        }
        
        return{-1,-1};
        
     }
        
        
        
        
        
        
        
       
};