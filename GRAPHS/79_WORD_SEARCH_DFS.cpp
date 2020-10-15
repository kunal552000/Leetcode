/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/


//CODE

class Solution {
public:
    
    bool wordsearch(vector<vector<char>>& board, string &word , int i, int j, int index)
    {
        if(index == word.size())
            return true;
       if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1 || board[i][j]      !=word[index])
             return false; 
        board[i][j] = '*';
        bool research = wordsearch(board,word,i+1,j,index+1) ||
            wordsearch(board,word,i-1,j,index+1) ||
            wordsearch(board,word,i,j+1,index+1) ||
            wordsearch(board,word,i,j-1,index+1);
        board[i][j] = word[index];
        return research;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(wordsearch(board,word,i,j,0))
                    return true;
            }
        }
        return false;
        
    }
};