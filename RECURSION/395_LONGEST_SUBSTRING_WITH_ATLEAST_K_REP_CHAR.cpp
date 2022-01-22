/*

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in 
this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105

*/


//CODE


class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size();
        
        if(k == 0 || k == 1)
            return n;
        
        if(k > n)
            return 0;
        
        unordered_map<char,int> mp;
        
        for(int i = 0; i < n; i++)
            mp[s[i]]++;
        
        int index = 0;
        
        while(mp[s[index]] >= k)
            index++;
        
        if(index == n)
            return n;
        
        int left = longestSubstring(s.substr(0,index),k);
        int right = longestSubstring(s.substr(index+1),k);
        
        return max(left,right);
        
        
    }
};