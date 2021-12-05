/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses 
at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have
 a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight
 without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000


*/


//CODE


class Solution {
public:
    
    
    int solve1(vector<int> &nums)
    {
        int n = nums.size();
        int memo[n-1];
        
        memo[0] = nums[0];
        memo[1] = max(nums[0],nums[1]);
        
        for(int i = 2; i <n-1; i++)
            memo[i] = max(memo[i-1],memo[i-2] + nums[i]);
        
        return memo[n-2];
        
        
    }
    
    int solve2(vector<int> &nums)
    {
        int n = nums.size();
        int memo[n];
        
        memo[1] = nums[1];
        memo[2] = max(nums[1],nums[2]);
        
        for(int i = 3; i < n; i++)
            memo[i] = max(memo[i-1],memo[i-2] + nums[i]);
        
        return memo[n-1];
        
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        
        int n = nums.size();
        
        int res1 = solve1(nums);
        int res2 = solve2(nums);
        
        return max(res1,res2);
        
        
        
    }
};