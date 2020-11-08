/*

Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.

*/

//CODE

class Solution {
public:
    int memo[1002][1002];
    int lcs(string &text1, string &text2, int n, int m)
    {
        if(n == 0 || m==0)
            return 0;
        if(memo[n][m] != -1)
            return memo[n][m];
       
        if(text1[n-1] == text2[m-1])
            return memo[n][m] =  1 + lcs(text1,text2,n-1,m-1);
       
        else
          return memo[n][m] =  max(lcs(text1,text2,n-1,m), lcs(text1,text2,n,m-1));
       
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo,-1,sizeof(memo));
        int n = text1.size();
        int m = text2.size();
        return lcs(text1,text2,n,m);
        
    }
};