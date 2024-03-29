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
-104 <= matrix[i][j], target <= 104

*/


//CODE


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end = (row*col)-1;
        
        while(start <= end)
        {
            int mid = start + ((end-start)/2);
            
            if(matrix[mid/col][mid%col] == target)
                return true;
            
            else if(matrix[mid/col][mid%col] > target)
                end = mid-1;
            
            else
                start = mid+1;
        }
        
        return false;
    }
};