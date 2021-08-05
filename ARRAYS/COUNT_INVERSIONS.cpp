/*

Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which 
takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 = N = 5*105
1 = arr[i] = 1018

*/


//CODE


class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
    long long int merge(long long arr[], long long int temp[], long long int left, long long int mid, long long int right)
    {
        long long int i,j,k;
        
        long long int count = 0;
        
        i = left;
        j = mid;
        k = left;
        
        while(i < mid && j <= right)
        {
            if(arr[i] <= arr[j])
            {
                temp[k] = arr[i];
                k++;
                i++;
            }
            
            else
            {
                temp[k] = arr[j];
                k++;
                j++;
                
                count = count + (mid - i);
            }
        }
        
        while(i < mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        
        while(j <= right)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
        
        for(i = left; i <= right; i++)
            arr[i] = temp[i];
            
        return count;
        
    }
    
    
    
    long long int mergesort(long long arr[], long long int temp[], long long int left, long long int right)
    {
        long long int mid;
        long long int count = 0;
        mid = left + ((right-left)/2);
        
        if(left < right)
        {
        
            count = count + mergesort(arr,temp,left,mid);
            count = count + mergesort(arr,temp,mid+1, right);
        
            count = count + merge(arr,temp,left,mid+1,right);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        long long int temp[N];
        long long int ans = mergesort(arr,temp,0,N-1);
        
        return ans;
    }

};