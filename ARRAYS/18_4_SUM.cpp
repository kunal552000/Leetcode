/*

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

//CODE

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n = nums.size();
        if(nums.size()<4)
            return res;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-3;i++)
        {
            if(i==0 || (i>0 && nums[i] != nums[i-1]))
            {
                 if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
                for(int j = i+1;j<n-2;j++)
                {
                    
                   
                    if(j==i+1 || (j > i+1 && nums[j] != nums[j-1]))
                
                    {
                        if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                        
                        int k = j+1;
                        int l = n-1;
                        while(k<l)
                        {
                            if(nums[i]+nums[j]+nums[k]+nums[l] == target)
                            {
                                res.push_back({nums[i],nums[j],nums[k],nums[l]});
                                while(k<l && nums[k] == nums[k+1]) k++;
                                while(k<l && nums[l] == nums[l-1]) l--;
                                k++;
                                l--;
                            }
                            else if(nums[i]+nums[j]+nums[k]+nums[l] < target)
                                k++;
                            else
                                l--;
                        }
                    }
                }
            }
        }
        return res;
        
    }
};