/*

Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

*/

//CODE


class Solution {
public:
    void heapify(vector<int>&nums, int n, int i)
    {
        int largest = i;
        int l = 2*i +1;
        int r = 2*i +2;
        if(l<n && nums[l] > nums[largest])
            largest = l;
        if(r<n && nums[r] > nums[largest])
            largest = r;
        if(largest != i)
        {
            swap(nums[i],nums[largest]);
            heapify(nums,n,largest);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i= n/2-1;i>=0;i--)
            heapify(nums,n,i);
        for(i=n-1;i>=0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
            
        
        return nums;
        
    }
};