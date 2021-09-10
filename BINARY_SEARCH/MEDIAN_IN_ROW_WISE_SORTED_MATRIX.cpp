/*


Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which 
takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1<= R,C <=150
1<= matrix[i][j] <=2000


*/


//CODE


class Solution{   
public:

    int lastocc(vector<int>& nums, int target)
    {
        int res = -1;
        
        int n = nums.size();
         int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + ((end - start) >> 1);
            
            if(target >= nums[mid])
            {
                
                start  = mid + 1;
            }
            
            else
                end = mid - 1;
            
        }
        return start;
        
    }
    
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here    
        
        int low = 0;
        int high = INT_MAX-1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            int count = 0;
            
            for(int i = 0; i < r; i++)
                count = count + lastocc(matrix[i],mid);
                
            if(count <= (r*c)/2)
            low = mid+1;
            
            else
            high = mid-1;
        }
        
        return low;
    }
};