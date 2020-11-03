/*


You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.


*/


//CODE

//A SLIGHT VARIATION OF COUNT SUSBET WITH GIVEN DIFF


class Solution {
public:
    int subset(vector<int>& nums, int subset1sum,int n)
    {
        int memo[n+1][subset1sum+1];
        memo[0][0] = 1;
        for(int i=1 ; i<subset1sum+1 ; i++)
        {
            
            memo[0][i]=0;
        }
        
        for(int i=1 ; i<n+1 ; i++)
        {  
            if(nums[i-1]==0)
            {
                memo[i][0]=2*memo[i-1][0];
            }
                
         else
            {
                 memo[i][0]=memo[i-1][0];
             }
        }
        
        for(int i = 1; i< n+1; i++)
        {
            for(int j = 1; j < subset1sum+1; j++)
            {
              
                if(nums[i-1] <= j)
                    memo[i][j] = memo[i-1][j-nums[i-1]] + memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
        return memo[n][subset1sum];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum  =0 ;
        for(int i = 0; i< nums.size();i++)
            sum = sum + nums[i];
        if(S > sum)
            return 0;
        if((S+sum)%2 != 0)
            return 0;
        int subset1sum = (S+sum)/2;
        return subset(nums,subset1sum,nums.size());
        
    }
};