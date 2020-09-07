/*

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.

*/

//CODE

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        if(size==0)
            return -1;
        int res = -1;
        
        int alphabet[26] = {0};
        for(int i =0;i<size;i++)
            alphabet[s[i]-'a']++;
        
        for(int i=0;i<size;i++)
        {
            if(alphabet[s[i]-'a']==1){
                res = i;
            break;
            }
        }
        return res;
        
    }
};