/*

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

*/


//CODE


class Solution {
public:
    
    int merge(vector<int>& nums, int low, int mid, int high)
    {
        int count = 0;
        int j = mid + 1;
        for(int i = low ; i<= mid; i++)
        {
            while(j <= high && nums[i] > 2LL * nums[j])
            {
                j++;
            }
            
            count = count + (j- (mid + 1) );
        }
        
        vector<int> temp;
        
        int left = low;
        int right = mid +1;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            
            else
                temp.push_back(nums[right++]);
        }
        
        while(left <= mid)
            temp.push_back(nums[left++]);
        
        while(right <= high)
            temp.push_back(nums[right++]);
        
        for(int i = low; i <= high; i++)
            nums[i] = temp[i-low];
        
        return count;
    }
    
    int mergesort(vector<int>& nums, int low, int high)
    {
        if(low >= high)
            return 0;
        
        int mid = (low+high)/2;
        int inv = mergesort(nums,low,mid);
        inv = inv + mergesort(nums,mid+1,high);
        inv = inv + merge(nums,low,mid,high);
        
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};