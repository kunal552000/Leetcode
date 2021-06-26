/*

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique

*/


//CODE

class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int> nums, vector<int> op)
    {
        if(nums.size() == 0)
        {
            res.push_back(op);
            return;
        }
        
        vector<int> op1 = op;
        vector<int> op2 = op;
        
        op2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);
        
        solve(nums,op1);
        solve(nums, op2);
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        solve(nums,op);
        
        return res;
    }
};