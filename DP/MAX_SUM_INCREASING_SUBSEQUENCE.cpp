/*

Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 = N = 103
1 = arr[i] = 105

*/


//CODE


class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    if(n == 0)
	    return 0;
	    
	    if(n == 1)
	    return arr[0];
	    
	   
	    int sum[n];
	    
	    for(int i = 0; i < n ; i++)
	    {
	        sum[i] = arr[i];
	    }
	    
	   
	    int mx = INT_MIN;
	    
	    for(int i = 1; i < n ; i++)
	    {
	        for(int j = 0; j < i ; j++)
	        {
	            if(arr[i] > arr[j])
	            {
	              
	                sum[i] = max(sum[i],arr[i] + sum[j]);
	            }
	        }
	        
	       
	    }
	    
	    for(int i = 0; i < n ; i++)
	    {
	        if(sum[i] > mx)
	        mx = sum[i];
	    }
	    return mx;
	}  
};