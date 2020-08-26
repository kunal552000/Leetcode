/*

Given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You should search for target in nums and if you found return its index, otherwise return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

*/


//CODE

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int low = 0;
        int high = nums.size()-1;
        while(low < high)
        {
            int mid = (low+high)/2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        int rotations = low;
        low = 0;
        high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int realmid = (mid+rotations)%nums.size();
            if(nums[realmid]==target)
                return realmid;
            if(nums[realmid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
        
    }
};