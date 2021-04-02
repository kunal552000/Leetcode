/*

Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-degreasing order.
1 <= k <= n^2

*/

//CODE

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        priority_queue<int> maxh;
        
       for(int i = 0; i < n ; i++)
       {
           for(int j = 0; j < n ; j++)
           {
               maxh.push(matrix[i][j]);
               
               if(maxh.size() > k)
                   maxh.pop();
           }
       }
        
        return maxh.top();
    }
};