/*

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

*/

//CODE

class Solution {
public:
    int longestPalindromeSubseq(string s) {
      string t = "";
       int n = s.size();
        for(int i = n-1; i>=0; i--)
            t = t + s[i];
        int memo[n+1][n+1];
        for(int i =0 ; i< n+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        for(int i = 1; i< n+1; i++)
        {
            for(int j = 1; j <n+1; j++)
            {
                if(s[i-1] == t[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i-1][j] , memo[i][j-1]);
            }
        }
        return memo[n][n];
        
    }
};