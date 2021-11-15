/*

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of 
elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.

*/


//CODE


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> ans;
        
        int n = nums.size();
        
        if(n == 0)
            return ans;
        
        sort(nums.begin(),nums.end());
        
        int lis[n];
        
        for(int i = 0; i < n; i++)
            lis[i] = 1;
        
        int max = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 && lis[i] < lis[j] + 1)
                {
                    lis[i] = lis[j] + 1;
                    
                    if(lis[i] > max)
                        max = lis[i];
                }
            }
        }
        
        int prev = -1;
        for(int i=n-1;i>=0;i--)
        {
            if(lis[i]==max &&  (prev%nums[i]==0 || prev==-1))
            {
                ans.push_back(nums[i]);
                max -=1;
                prev = nums[i];
            }
        }
        return ans;
        
    }
};