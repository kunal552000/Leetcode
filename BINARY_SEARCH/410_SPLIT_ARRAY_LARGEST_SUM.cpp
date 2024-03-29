/*


Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)


*/


//CODE


class Solution {
public:
    
    bool isvalid(vector<int>& nums, int n, int m, int mid)
    {
        int counter = 1;
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            
            if(sum > mid)
            {
                counter++;
                sum = nums[i];
            }
            
            if(counter > m)
                return false;
        }
        
        return true;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        
        int maxi = 0;
        int sum = 0;
        
        for(int i = 0 ; i < n; i++)
        {
            if(nums[i] > maxi)
                maxi = nums[i];
            
            sum = sum + nums[i];
        }
        
        int low = maxi;
        int high = sum;
        
        int res = -1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(isvalid(nums,n,m,mid) == true)
            {
                res = mid;
                high = mid - 1;
            }
            
            else
                low = mid + 1;
        }
        
        return res;
    }
};