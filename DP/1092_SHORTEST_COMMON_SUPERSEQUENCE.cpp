/*

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
 

Note:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.

*/

//CODE

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        int memo[m+1][n+1];
        for(int i = 0 ; i< m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        for(int i = 1; i< m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(str1[i-1] == str2[j-1])
                    memo[i][j] = memo[i-1][j-1] + 1;
                else
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        int i = m;
        int j = n;
        string res = "";
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1]){
                res = res + str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(memo[i-1][j] > memo[i][j-1]){
                    res = res + str1[i-1];
                    i--;
                    
                }
                else{
                    res = res + str2[j-1];
                    j--;
            }
            }
        }
        while( i > 0)
        {
            res = res + str1[i-1];
            i--;
        }
        while( j > 0)
        {
            res = res + str2[j-1];
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};