/*

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the given array.

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which takes the array of integers arr,
n and x as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 = N = 10^5
1 = Arr[i] = 10^6
1 = X = 10^6

 */

//CODE

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */

	int res = -1;

	int firstocc(int arr[], int n, int target)
    {
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if(target == arr[mid])
            {
                res = mid;
                end = mid - 1;
            }
            else if(target < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
            
        }
        return res;
    }
    
    int secocc(int arr[], int n, int target)
    {
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if(target == arr[mid])
            {
                res = mid;
                start = mid + 1;
            }
            else if(target < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
            
        }
        return res;
    }
    
	int count(int arr[], int n, int x) {
	    
	    
	    int first = firstocc(arr,n,x);
            int second = secocc(arr,n,x);
        
            if(first + second < 0)
                return 0;
        
           return second - first + 1;
	}
};