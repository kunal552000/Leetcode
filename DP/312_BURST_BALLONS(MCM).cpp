/*

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 = n = 500, 0 = nums[i] = 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/

//CODE

//SAME CONCEPT... ADD 1 AT BRGINING AND END OF THE ARRAY THEN DO MATRIX CHAIN MULTIPLICATION.

class Solution {
public:
    int memo[503][503];
    int ballon(vector<int> &nums1,int i, int j)
    {
        if(i >= j)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        int max = INT_MIN;
        for(int k = i; k < j; k++)
        {
            int temp = ballon(nums1,i,k) + ballon(nums1,k+1,j) +(nums1[i-1] * nums1[k] * nums1[j]);
            if(temp > max)
                max = temp;
            
        }
        return memo[i][j] = max;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
       memset(memo,-1,sizeof(memo));
        vector<int> nums1(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            nums1[i + 1] = nums[i];
    }
          
        return ballon(nums1,1,nums1.size()-1);
    }
};