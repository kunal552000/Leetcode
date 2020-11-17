/*

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up:

Could you come up with the O(n2) solution?
Could you improve it to O(n log(n)) time complexity?

*/

//CODE

class Solution {
public:
    int lcs(vector<int>& nums, vector<int>& arr, int m,int n)
    {
        int memo[m+1][n+1];
        for(int i = 0; i < m+1; i++)
        {
            for(int j = 0 ; j < n+1; j++)
            {
                if( i== 0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(nums[i-1] == arr[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i-1][j] , memo[i][j-1]);
            }
        }
        return memo[m][n];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr(nums.size());
        for(int i = 0;i<nums.size();i++)
            arr[i] = nums[i];
        vector<int>::iterator ip; 
        sort(arr.begin(),arr.end());
        
       ip =   unique(arr.begin(),arr.begin()+arr.size());
        arr.resize(distance(arr.begin(), ip)); 
        return lcs(nums,arr,nums.size(),arr.size());
        
    }
};