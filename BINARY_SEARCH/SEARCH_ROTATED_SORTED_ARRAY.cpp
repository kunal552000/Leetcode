/*

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the 
resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

*/

//CODE

class Solution {
public:
    
    int bs(vector<int> &arr, int start, int end, int target)
    {
         while(start <= end)
       {
           int mid = start + ((end - start)/2);
           if(arr[mid] == target)
           return mid;
           
           else if(arr[mid] > target)
           end = mid - 1; 
           
           else
           start = mid + 1;
       }
       return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
         int low =0;
        int high = n-1;
        while(low < high)
        {
            int mid = low + ((high-low)/2);
            if(nums[mid] > nums[high])
                low = mid+1;
            else
                high = mid;
        }
        
        int minele = low;
        
        int leftside = bs(nums,0,minele-1,target);
        int rightside = bs(nums,minele,n-1,target);
        
        if(leftside == -1 && rightside == -1)
            return -1;
        return max(leftside, rightside);

        
    }
};