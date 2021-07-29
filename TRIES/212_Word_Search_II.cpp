/*

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.


*/

//CODE


class Solution {
public:
    
    struct Trienode
    {
        bool endshere = false;
        Trienode* child[26] = {NULL};
        string word = "";
    };
    
    
    Trienode* insert(vector<string>& words)
    {
       Trienode* root = new Trienode();
        int n = words.size();
        
        for(int j = 0; j < n ; j++)
        {
            string s = words[j];
            
            int index = 0;
            Trienode* curr = root;
        
            for(int i = 0; i < s.size() ; i++)
            {
                int index = s[i] - 'a';
                if(curr->child[index] == NULL)
                    curr->child[index] = new Trienode();
            
                curr = curr->child[index];
            
            }
        
            curr->endshere = true;
            curr->word = s;
        }
        return root;
    }
    
    void solve(vector<vector<char>>& board, int i, int j, vector<string>& ans,Trienode* curr)
    {
        
        int m = board.size();
        int n = board[0].size();
        int index = board[i][j] - 'a';
        
        if( board[i][j]=='$' || curr->child[index] == NULL)
            return;
        
        curr = curr->child[index];
        if(curr->endshere == true)
        {
            ans.push_back(curr->word);
            curr->endshere = false;
            
        }
        
        char ch = board[i][j];
        board[i][j] = '$';
        
      if(i < m-1)  solve(board,i+1,j,ans,curr);
      if(i > 0)  solve(board,i-1,j,ans,curr);
      if(j < n-1)  solve(board,i,j+1,ans,curr);
     if(j > 0)   solve(board,i,j-1,ans,curr);
        
        board[i][j] = ch;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trienode* root = insert(words);
        
        int row = board.size();
        int columns = board[0].size();
       
        
        vector<string> ans;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                solve(board,i,j,ans,root);
            }
        }
        
        return ans;
    }
};