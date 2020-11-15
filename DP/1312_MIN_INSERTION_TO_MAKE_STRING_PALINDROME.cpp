/*

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
Example 4:

Input: s = "g"
Output: 0
Example 5:

Input: s = "no"
Output: 1
 

Constraints:

1 <= s.length <= 500
All characters of s are lower case English letters.

*/



//CODE

class Solution {
public:
    int lps(string &s, string &t)
    {
       int m  = s.size();
        int n = t.size();
        int memo[m+1][n+1];
        for(int i = 0 ; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j <n+1; j++)
            {
                if(s[i-1] == t[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i][j-1] , memo[i-1][j]);
            }
        }
        return m - memo[m][n];
    }
    int minInsertions(string s) {
        string t;
        t = s;
        reverse(t.begin(),t.end());
        return lps(s,t);
        
    }
};