/*

You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int size = n+1;
        int arr[size];
        for(int i = 0; i < size;i++)
            arr[i] = 0;
        int dup,miss;
        for(int i = 0; i < nums.size(); i++ )
            arr[nums[i]]++;
        for(int i = 1; i < size; i++)
        {
            if(arr[i] > 1)
                dup = i;
            if(arr[i] == 0)
                miss = i;
            
        }
        res.push_back(dup);
        res.push_back(miss);
        return res;
        
        
        
    }
};which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 10^4
1 <= nums[i] <= 10^4

*/

//CODE


