/*

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/


//CODE


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for(string word : wordList)
            set.insert(word);
        if(set.find(endWord)==set.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i =0;i<size;i++)
            {
                string curr = q.front();
                q.pop();
                for(int j =0;j<curr.size();j++)
                {
                    char original = curr[j];
                    for(char c = 'a'; c <='z';c++)
                    {
                        if(curr[j] == c)
                            continue;
                        curr[j] = c;
                        if(curr == endWord)
                            return count+1;
                        if(set.find(curr) != set.end())
                        {
                            q.push(curr);
                            set.erase(curr);
                        }
                    }
                    curr[j] = original;
                }
            
            
            }
            count++;
        
        }
        return 0;
        
        
    }
};