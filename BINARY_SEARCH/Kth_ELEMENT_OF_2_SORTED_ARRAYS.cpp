/*


Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that 
would be at the k�th position of the final sorted array.
 

Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function kthElement() which takes the 
arrays arr1[], arr2[], its size N and M respectively and an integer K as inputs and returns the element at the Kth position.


Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))


Constraints:
1 <= N, M <= 106
1 <= arr1i, arr2i <= 106
1 <= K <= N+M


*/


//CODE


class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m)
        {
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int low = max(0,k-m);
        int high = min(k,n);
        
        while(low <= high)
        {
            int cut1 = low + (high-low)/2;
            int cut2 = k - cut1;
            
            int l1,l2,r1,r2;
            
            if(cut1 == 0)
                l1 = INT_MIN;
            else
                l1 = arr1[cut1-1];
                
            if(cut2 == 0)
                l2 = INT_MIN;
            else
                l2 = arr2[cut2-1];
                
            if(cut1 == n)
                r1 = INT_MAX;
            else
                r1 = arr1[cut1];
                
            if(cut2 == m)
                r2 = INT_MAX;
            else
                r2 = arr2[cut2];
                
            if(l1 <= r2 && l2 <= r1)
            return max(l1,l2);
            
            else if(l1 > r2)
            high = cut1-1;
            
            else
            low = cut1+1;
            
        }
        
        return 1;
        
        
    }
};