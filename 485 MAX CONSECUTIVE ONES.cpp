//Given a binary array, find the maximum number of consecutive 1s in this array.

//Example 1:
//Input: [1,1,0,1,1,1]
//Output: 3
//Explanation: The first two digits or the last three digits are consecutive 1s.
 //   The maximum number of consecutive 1s is 3.
//Note:

//The input array will only contain 0 and 1.
//The length of input array is a positive integer and will not exceed 10,000

//CODE :-


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int count =0;
        int max = -32768;
        while(i<n)
        {
            if(nums[i]==1)
            {
                count++;
                i++;
            }
            else
            {
                if(count>max)
                    max = count;
                count = 0;
                i++;
            }
        }
        if(count>max)
            return count;
        else
            return max;
        
    }
};