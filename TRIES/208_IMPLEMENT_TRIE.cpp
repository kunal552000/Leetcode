/*

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

*/

//CODE


class Trie {
public:
    /** Initialize your data structure here. */
    
    struct TrieNode
    {
        //char val;
        bool endshere = false;
        TrieNode* child[26] = {NULL};
        
    };
    
    TrieNode* root;
    
    
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        int index = 0;
        
        TrieNode* curr = root;
        
        for(int i = 0; i < n ; i++)
        {
            index = word[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();
            
            curr = curr->child[index];
                
        }
        
        curr->endshere = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        int index = 0;
        
        TrieNode* curr = root;
        
        for(int i = 0; i < n ; i++)
        {
            int index = word[i] - 'a';
            
            if(curr->child[index] == NULL)
                return false;
            
            curr = curr->child[index];
        }
        
        return curr->endshere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        int index = 0;
        
        TrieNode *curr = root;
        
        for(int i = 0; i < n ; i++)
        {
            int index = prefix[i] - 'a';
            
            if(curr->child[index] == NULL)
                return false;
            
            curr = curr->child[index];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

