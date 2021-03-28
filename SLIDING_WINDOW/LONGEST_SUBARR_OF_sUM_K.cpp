/*

Given an array containing N integers and an integer K., 
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0

Your Task:
This is a function problem. The input is already taken care of by the driver code. 
You only need to complete the function smallestSubsegment() that takes an array (A), sizeOfArray (n),  
sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1<=N<=105
-105<=A[i], K<=105

*/

//CODE

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int sum = 0;
        int res = 0;
        unordered_map<int , int> mp;
        
        for(int i = 0; i < N ; i++)
        {
            sum = sum + A[i];
            
            if(sum == K)
            res = i + 1;
            
            if(mp.find(sum) == mp.end())
            mp[sum] = i;
            
            
            if(mp.find(sum - K) != mp.end())
            {
                int index = mp[sum - K];
                
                if(res < i - index)
                 res = i - index;
            }
        }
        return res;
    } 

};