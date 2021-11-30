/*

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/


//CODE


class Solution {
public:
    
    
    int largest_rectangle(vector<int> heights)
    {
        vector<int> left;
        vector<int> right;
        
        stack<int> s;
        
        int n = heights.size();
        
        
        //nsl
        
        for(int i = 0; i < n ; i++)
        {
            if(s.empty())
                left.push_back(0);
            
            else if(heights[i] > heights[s.top()])
                left.push_back(s.top() + 1);
            
            else if(!s.empty() && heights[i] <= heights[s.top()])
            {
                while(!s.empty() && heights[i] <= heights[s.top()])
                    s.pop();
                
                if(s.empty())
                    left.push_back(0);
                
                else
                    left.push_back(s.top() + 1);
            }
            
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        //nsr
        
        for(int i = n-1; i >= 0 ; i--)
        {
            if(s.empty())
                right.push_back(n-1);
            
            else if(heights[i] > heights[s.top()])
                right.push_back(s.top() - 1);
            
            else if(!s.empty() && heights[i] <= heights[s.top()])
            {
                while(!s.empty() && heights[i] <= heights[s.top()])
                    s.pop();
                
                if(s.empty())
                    right.push_back(n-1);
                
                else
                    right.push_back(s.top() - 1);
            }
            
            s.push(i);
        }
        
        reverse(right.begin(),right.end());
        
        int ans = 0;
        
        for(int i = 0; i < n ; i++)
        {
            ans = max(ans,(right[i] - left[i] + 1)*heights[i]);
        }
        
        return ans;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
       int m = matrix.size();
        
        if(m == 0)
            return 0;
        
        int n = matrix[0].size();
        
        vector<int> curRow;
        int row = 0;
        int col = 0;
        
        while(col < n)
        {
            if(matrix[row][col] == '0')
                curRow.push_back(0);
            else
                curRow.push_back(1);
            
            col++;
        }
        
        int res  = largest_rectangle(curRow);
        
        for(int i = 1; i < m ;i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(matrix[i][j] == '1')
                    curRow[j] = curRow[j] + 1;
                
                else
                    curRow[j] = 0;
            }
            
            int curRes = largest_rectangle(curRow);
            res = max(res,curRes);
        }
        
        return res;
    }
};