/*

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

*/

//CODE

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>> ans;
        if(strs.size() == 0)
              return ans;
        map<string,vector<string>> anagrams;
        for(string s: strs){
            string sorted = s;
            sort(sorted.begin(),sorted.end());
            anagrams[sorted].push_back(s);
        }
        map<string,vector<string>>::iterator itr = anagrams.begin();
        while(itr != anagrams.end())
        {
            ans.push_back(itr->second);
            itr++;
        }
        return ans;
        
    }
};