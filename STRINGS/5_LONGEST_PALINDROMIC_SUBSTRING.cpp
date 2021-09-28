/*

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.


*/


//CODE


class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        
        int low,high;
        
        int start = 0;
        int end = 1;
        
        int n = s.size();
        
        for(int i = 1; i < n ; i++)
        {
            //even substring
            
            low = i-1;
            high = i;
            
            while(low >= 0 && high < n && s[low] == s[high])
            {
                if(high - low + 1 > end)
                {
                    start = low;
                    end = high - low + 1;
                }
                
                low--;
                high++;
            }
            
            
            //odd substring
            low = i-1;
            high = i+1;
            
            while(low >= 0 && high < n && s[low] == s[high])
            {
                if(high - low + 1 > end)
                {
                    start = low;
                    end = high - low + 1;
                }
                
                low--;
                high++;
            }
        }
        
        for(int i = start; i <= start+end-1; i++)
            res = res + s[i];
        
        return res;
    }
};