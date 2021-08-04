/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

*/



//CODE


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i,j;
        int index1,index2;
        
        for(int i = n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                index1 = i;
                break;
            }
        }
        
        if(index1 < 0)
            reverse(nums.begin(),nums.end());   //edge case i.e if input is sorted in desc order then next permutation is reverse of that
        
        else
        {
            for(j = n-1; j > index1; j--)
            {
                if(nums[j] > nums[index1])
                {
                    index2 = j;
                    break;
                }
            }
        
        
        swap(nums[index1] , nums[index2]);
        reverse(nums.begin()+index1+1, nums.end());
        }
        
    }
};