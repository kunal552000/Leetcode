/*

Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
 

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9


*/


//CODE


class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        
        vector<long> sum(n+1,0);
        int res = INT_MAX;
        
        for(int i = 0; i < n; i++)
            sum[i+1] = sum[i] + A[i];
        
        deque<int> q;
        
        for(int i = 0; i < n+1; i++)
        {
            while(!q.empty() && sum[i] - sum[q.front()] >= K)
            {
                res = min(res, i - q.front());
                q.pop_front();
            }
            
            while(!q.empty() && sum[i] - sum[q.back()] <= 0)
                q.pop_back();
            
            q.push_back(i);
        }
        
        if(res == INT_MAX)
            return -1;
        
        return res;
    }
};