/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/

//code

class Solution {
public:
    /*
    approach:-
    1 .find lcs
    2. return (word1 size - lcs) + (word2 size - lcs)
    */
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int memo[m+1][n+1];
        for(int i = 0; i< m+1;i++)
        {
            for(int j = 0;j<n+1;j++)
            {
                if(i ==0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        for(int i = 1; i <m+1; i++)
        {
            for(int j = 1; j< n+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        int val = memo[m][n];
        return (m-val) + (n-val);
        
    }
};