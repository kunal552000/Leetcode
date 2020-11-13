/*

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters

*/


//CODE

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int memo[m+1][n+1];
        for(int i = 0; i<m+1; i++)
        {
            for(int j = 0 ; j < n+1; j++)
            {
                if( i == 0)
                    memo[i][j] = j;
                if( j == 0)
                    memo[i][j] = i;
            }
        }
        for(int i  = 1 ; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                    memo[i][j] = memo[i-1][j-1];
                else
                {
                    int res =  min(memo[i-1][j], memo[i][j-1]);
                    memo[i][j] = min(res, memo[i-1][j-1]) + 1;
                }
            }
        }
        return memo[m][n];
        
    }
};