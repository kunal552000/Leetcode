/*

A conveyor belt has packages that must be shipped from one port to another within D days.

The ith package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, 
so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], D = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= D <= weights.length <= 5 * 104
1 <= weights[i] <= 500

*/


//code

class Solution {
public:
    
    //SAME AS ALLOCATE MIN NO OF PAGES PROBLEM
    
    bool isvalid(vector<int> &weights, int n, int D, int mid)
    {
        int cap = 1;
        int sum = 0;
        
        for(int i = 0; i < n ; i++)
        {
            sum = sum + weights[i];
            
            if(sum > mid)
            {
                cap++;
                sum = weights[i];
            }
            
            if(cap > D)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        
        int maxi = INT_MIN;
        int sum = 0;
        
        int n = weights.size();
        if(n < D)
            return -1;
        
        for(int i = 0; i < n; i++)
        {
            if(weights[i] > maxi)
                maxi = weights[i];
            
            sum = sum + weights[i];
        }
        
        int start = maxi;
        int end = sum;
        
        int res = -1;
        
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if(isvalid(weights,n,D,mid) == true)
            {
                res = mid;
                end = mid - 1;
            }
            
            else
                start = mid + 1;
        }
        return res;
        
        
        
    }
};