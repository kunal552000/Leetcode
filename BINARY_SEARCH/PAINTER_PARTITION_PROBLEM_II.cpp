/*

Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] 
where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter 
will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
Example 2:

Input:
n = 4
k = 2
arr[] = {10,20,30,40}
Output: 60
Explanation: The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60

Your task:
Your task is to complete the function minTime() which takes the integers n and k and the array arr[] as input and returns 
the minimum time required to paint all partitions.


Expected Time Complexity: O(n log m) , m = sum of all boards' length
Expected Auxiliary Space: O(1)


Constraints:
1 = n = 105
1 = k = 105
1 = arr[i] = 105

*/


//CODE


class Solution
{
  public:
  
    bool isvalid(int arr[],int n,int k, long long mid)
    {
        long long painter = 1;
        long long sum = 0;
        
        for(long long i = 0; i < n ; i++)
        {
            sum = sum + arr[i];
            if(sum > mid)
            {
                painter++;
                sum = arr[i];
            }
            
            if(painter > k)
            return false;
        }
        
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sum = 0;
        long long maxi = 0;
        
        for(long long i = 0; i < n ; i++)
        {
            if(arr[i] > maxi)
            maxi = arr[i];
            
            sum = sum + arr[i];
        }
        
        long long low = maxi;
        long long high = sum;
        long long res = -1;
        
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            
            if(isvalid(arr,n,k,mid) == true)
            {
                res = mid;
                high = mid - 1;
            }
            
            else
            low = mid + 1;
        }
    
    
    return res;
    }
};