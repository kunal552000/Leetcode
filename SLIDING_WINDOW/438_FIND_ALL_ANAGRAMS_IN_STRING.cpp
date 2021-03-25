/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

//CODE

//THIS IS SAME AS COUNT OCCURENCES OF ANAGRAMS...


class Solution {
public:
    
    bool check(int phash[26], int shash[26])
    {
        for(int i =0;i<26;i++)
        {
            if(phash[i] != shash[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
	    
	    int n = s.size();
	    
	    int k = p.size(); //window size
	    
        int phash[26] = {0};
        int shash[26] = {0};
        
        for(int a = 0; a < k; a++)
            phash[p[a]-'a']++;
        
        int i =0;
        int j = 0;
        
        while(j < n)
        {
            shash[s[j]-'a']++;
            
            
            if(j-i+1 < k)
                j++;
            
            else if(j-i+1 == k)
            {
                if(check(phash,shash) == true)
                    ans.push_back(i);
                
                shash[s[i]-'a']--;
                
                i++;
                j++;
            }
            
        }
	    return ans;
    }
};