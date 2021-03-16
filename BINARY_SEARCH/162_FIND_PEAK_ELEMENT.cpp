/*

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -8.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-2^31 <= nums[i] <= 2^31 - 1
nums[i] != nums[i + 1] for all valid i.
 

Follow up: Could you implement a solution with logarithmic complexity?

*/

//CODE

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return 0;
      
        
        int start = 0;
        int end = n-1;
        
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            if(mid > 0 && mid < n-1)
          {
            
            if( nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            
            else if(nums[mid - 1] > nums[mid])
                end = mid - 1;
            
            else
                start = mid + 1;
            }
            else if(mid == 0)
            {
                if(nums[0] > nums[1])
                    return 0;
                return 1;
            }
            else if(mid == n-1)
            {
                if(nums[n-1] > nums[n-2])
                    return n-1;
                return n-2;
            }
        }
        return 0;
        
    }
};