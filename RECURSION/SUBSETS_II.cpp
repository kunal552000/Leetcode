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
    
    
void solve(int index, vector<int>& ds, vector<int> &nums, vector<vector<int>>& res)
    {
        res.push_back(ds);
        for(int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i-1])
                continue;
            ds.push_back(nums[i]);
            solve(i+1,ds,nums,res);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        
        sort(nums.begin(),nums.end());
        
        solve(0,ds,nums,res);
        return res;
    }
};