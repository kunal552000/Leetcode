/*

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/

//CODE

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i;
        int left = 1;
        for(i=0;i<n;i++)
        {
            if(i > 0)   //No element on the left of 0th element
                left = left * nums[i-1];
            res[i] = left;
        }
        int right = 1;
        for(i=n-1;i>=0;i--)
        {
            if(i < n-1) //No element on the right of last element
                right = right * nums[i+1];
            res[i] = res[i]*right;   //Multiplying left product with right product of that element
        }
        return res;
    
        
    }
};