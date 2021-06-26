/*


Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10


*/


//CODE


class Solution {
public:
    
    vector<vector<int>> res;
    set<vector<int>> s;
    
    void solve(vector<int>nums, vector<int> op)
    {
        if(nums.size() == 0)
        {
            s.insert(op);
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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<int> op;
         solve(nums,op);
        
        for(auto it : s)
            res.push_back(it);
        
        return res;
    }
};