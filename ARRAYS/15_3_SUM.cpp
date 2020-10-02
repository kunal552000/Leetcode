/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

//CODE

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int  i = 0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i] != nums[i-1]))
            {
                if(nums[i] > 0)
                    break;
                int j = i+1;
                int k = n-1;
                while(j<k){
                    if(nums[i]+nums[j]+nums[k] == 0)
                    {
                        res.push_back({nums[i],nums[j],nums[k]});
                        while(j<k && nums[j] == nums[j+1]) j++;
                        while(j<k && nums[k] == nums[k-1]) k--;
                        j++;
                        k--;
                    }
                    else if(nums[i]+nums[j]+nums[k] < 0){
                      //  while(j<k && nums[j] == nums[j+1] ) j++;  THIS IS OPTIONAL
                        j++;
                    }
                    else{
                       // while(j<k && nums[k] == nums[k-1]) k--; THIS IS OPTIONAL
                        k--;
                    }
                }
            }
        }
        return res;
        
        
    }
};
