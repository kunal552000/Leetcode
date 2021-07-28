/*

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may 
contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.


*/


//CODE



class WordDictionary {
public:
    
    /** Initialize your data structure here. */
    
    struct Trienode
    {
        bool endshere = false;
        Trienode* child[26] = {NULL};
    };
    
    struct Trienode* root;
    
    WordDictionary() {
        root = new Trienode();
    }
    
    bool searching(string s, Trienode *curr, int index, int n)
    {
        if(s[index] == '.')
        {
            bool res = false;
            Trienode* current = curr;
            for(int i = 0; i < 26; i++)
            {
                if(index == n-1 && curr->child[i] != NULL)
                {
                    current = curr->child[i];
                    if(current->endshere == true)
                        res = true;
                    else
                        res = false;
                }
                
                else if(curr->child[i] != NULL && searching(s,curr->child[i],index+1,n))
                    return true;
            }
            
            return res;
                    
            }
         
         else if(curr->child[s[index]-'a'])
        {
            if(index == n-1)
            {
                curr = curr->child[s[index]-'a'];
                
                if(curr->endshere == true)
                    return true;
                return false;
                
            }
            return searching(s,curr->child[s[index]-'a'],index+1,n);
        }
        return false;
    }
    
   
    void addWord(string word) {
        int n = word.size();
        int index = 0;
        Trienode* curr = root;
        
        for(int i = 0; i < n ; i++)
        {
            index = word[i] - 'a';
            
            if(curr->child[index] == NULL)
                curr->child[index] = new Trienode();
            
            curr = curr->child[index];
        }
        
        curr->endshere = true;
    }
    
    bool search(string word) {
        int n = word.size();
        return searching(word,root,0,n);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */