/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4

*/

//CODE

//complexity has been reduced to O(m+n) from O(m*n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int row = matrix.size();
        int col = matrix[0].size();
        
         int i = 0; //1st row
         int j = col - 1; //last col.. so we are at right corner top element 
        
        while(i < row && j >= 0)
        {
            if(matrix[i][j] > target)
                j--;
            
            else if(matrix[i][j] < target)
                i++;
            
            else 
                return true;
        }
        return false;
        
    }
};