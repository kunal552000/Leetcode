/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in 
candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/


//CODE


class Solution {
public:
    
    
    void solve(int index, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>&res)
    {
        //base case 
        if(target == 0)
        {
            res.push_back(ds);
            return;
        }
        
        for(int i = index; i < arr.size(); i++)
        {
            if(i != index && arr[i] == arr[i-1])
                continue;
            
            if(arr[i] > target)
                break;
            
            ds.push_back(arr[i]);
            solve(i+1,target-arr[i],arr,ds,res);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> res;
        vector<int> ds;
        
        solve(0,target,candidates,ds,res);
        return res;
    }
};