/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

*/


//CODE


//I HAVE USED 0(n) SPACE....O(1) SPACE REQUIRES XOR OPERATION (BIT MANIPULATION)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for(int i = 0;i<nums.size();i++)
        {
            if(s.find(nums[i]) ==s.end())
                s.insert(nums[i]);
            else
                s.erase(nums[i]);
        }
        return *s.begin();
        
        
    }
};

