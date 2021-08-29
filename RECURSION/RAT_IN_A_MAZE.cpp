/*

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat 
can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked 
and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as 
input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 = N = 5
0 = m[i][j] = 1


*/


//CODE



void solve(int i, int j, vector<vector<int>>&m, int n, vector<string>& res, string move, vector<vector<int>>& vis)
{
    if(i == n-1 && j == n-1)
    {
        res.push_back(move);
        return;
    }
    
    //downward
    
    if(i+1 < n && vis[i+1][j] == 0 && m[i+1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i+1,j,m,n,res,move+'D',vis);
        vis[i][j] = 0;
    }
    
    //left
    
    if(j-1 >= 0 && vis[i][j-1] == 0 && m[i][j-1] == 1)
    {
        vis[i][j] = 1;
        solve(i,j-1,m,n,res,move+'L',vis);
        vis[i][j] = 0;
    }
    
    //right
    
    if(j+1 < n && vis[i][j+1] == 0 && m[i][j+1] == 1)
    {
        vis[i][j] = 1;
        solve(i,j+1,m,n,res,move+'R',vis);
        vis[i][j] = 0;
    }
    
    //upward
    if(i-1 >= 0 && vis[i-1][j] == 0 && m[i-1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i-1,j,m,n,res,move+'U',vis);
        vis[i][j] = 0;
    }
    
    
}



class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> res;
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        if(m[0][0] == 1)
        solve(0,0,m,n,res,"",vis);
        
        return res;
    }
};
