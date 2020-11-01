/*

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/

//CODE

class Solution {
public:
    bool subset(vector<int> &nums, int target, int n)
    {
        bool memo[n+1][target+1];
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j <target+1;j++)
            {
                if(i == 0)
                    memo[i][j] = false;
                if(j == 0)
                    memo[i][j] = true;
            }
        }
        for(int i =1;i<n+1;i++)
        {
            for(int j = 1 ; j<target+1; j++)
            {
                if(nums[i-1] <= j)
                    memo[i][j] = memo[i-1][j-nums[i-1]] || memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
        return memo[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i = 0;i<nums.size();i++)
            sum = sum + nums[i];
        if(sum % 2)
            return false;
        return subset(nums,sum/2,nums.size());
        
    }
};