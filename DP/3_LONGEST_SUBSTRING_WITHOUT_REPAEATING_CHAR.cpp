/*

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

//CODE


/*

APPROACH

1 Use an unordered set.
2 initialize 2 var i and j with 0 and a res with 0 that will acrry the length.
3 check i and j both should be less than size of string
4 inside while loop 
	a. if jth char of string is not present in set
		insert jth char in set
		increment j by j+1
		res = max(res,j-i)
        b. else
 		erase the ith char from set
		incremnt i by 1

5 return res
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        unordered_set<char> set;
        int i = 0;
        int j = 0;
        int res = 0;
        while(i < n && j  < n)
        {
            if(set.find(s[j]) == set.end())
            {
                set.insert(s[j]);
                j++;
                res = max(res,j-i);
                
            }
            else
            {
                set.erase(s[i]);
                i++;
            }
            
        }
        return res;
        
    }
};