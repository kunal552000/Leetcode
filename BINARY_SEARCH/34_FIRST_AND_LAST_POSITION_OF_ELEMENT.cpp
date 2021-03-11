/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9

*/

//CODE

class Solution {
public:
    int res = -1;
    
    int firstocc(vector<int> &nums, int n, int target)
    {
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if(target == nums[mid])
            {
                res = mid;
                end = mid - 1;
            }
            else if(target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
            
        }
        return res;
    }
    
    int secocc(vector<int> &nums, int n, int target)
    {
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if(target == nums[mid])
            {
                res = mid;
                start  = mid + 1;
            }
            else if(target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
            
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0)
        {
            ans.push_back(res);
            ans.push_back(res);
            
        }
        else
        {
            int first = firstocc(nums,n,target);
            int second = secocc(nums,n,target);
            ans.push_back(first);
            ans.push_back(second);
        }
        return ans;
    }
};

