/*

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/

//CODE

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int arraysum = 0;
        int rangesum = (n*(n+1))/2;
        int i;
        for(i=0;i<n;i++)
            arraysum = arraysum+nums[i];
        return rangesum-arraysum;
        
    }
};