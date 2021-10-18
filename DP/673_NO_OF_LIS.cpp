/*

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 

Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106

*/


//CODE


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        if(n == 1)
            return 1;
        
        int lis[n];
        int res = 1;
        
        vector<int> count(n,1);
        
        int no_of_lis = 0;
        
        for(int i = 0; i < n ; i++)
        {
            lis[i] = 1;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && lis[i] < lis[j] + 1)
                {
                    lis[i] = lis[j] + 1;
                    count[i] = count[j];
                }
                
                else if(nums[i] > nums[j] && lis[i] == lis[j] + 1)
                {
                    count[i] = count[i] + count[j];
                }
            }
            
            res = max(res,lis[i]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(lis[i] == res)
                no_of_lis = no_of_lis + count[i];
        }
        
        return no_of_lis;
        
    }
};