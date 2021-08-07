/*

Given an integer array of size n, find all elements that appear more than ? n/3 ? times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

*/


//CODE


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        vector<int> res;
        
        int n = nums.size();
        
        for(int i = 0; i < n ; i++)
        {
            if(nums[i] == num1)
                cnt1++;
            
            else if(nums[i] == num2)
                cnt2++;
            
            else if(cnt1 == 0)
            {
                num1 = nums[i];
                cnt1 = 1;
            }
            
            else if(cnt2 == 0)
            {
                num2 = nums[i];
                cnt2 = 1;
            }
            
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        
         cnt1 = 0;
         cnt2 = 0;
        for(int i = 0; i < n ; i++)
        {
            if(nums[i] == num1)
            {
                cnt1++;
            }
            
            else if(nums[i] == num2)
                cnt2++;
        }
        
        if(cnt1 > n/3)
            res.push_back(num1);
        
        if(cnt2 > n/3)
            res.push_back(num2);
        
        return res;
    }
};