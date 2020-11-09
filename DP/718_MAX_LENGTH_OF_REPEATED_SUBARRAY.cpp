/*

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
 

Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

*/

//CODE

//THIS IS A VARIATION OF LONGEST COMMON SUBSTRING.
//IN PLACE OF STRING ARRAYS ARE USED.


class Solution {
public:
    int subarray(vector<int>& A, vector<int>& B, int m, int n)
    {
        int memo[m+1][n+1];
        for(int i = 0; i< m+1;i++)
        {
            for(int j = 0; j<n+1; j++)
            {
                if(i == 0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        for(int i = 1; i< m+1; i++)
        {
            for(int  j = 1; j<n+1;j++)
            {
                if(A[i-1] == B[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = 0;
            }
        }
        int max = 0;
        for(int i = 0; i< m+1; i++)
        {
            for(int j = 0; j <n+1; j++)
            {
                if(memo[i][j] > max)
                    max = memo[i][j];
            }
        }
        return max;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        return subarray(A,B,m,n);
        
    }
};
