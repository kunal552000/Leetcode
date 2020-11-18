/*

Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.

Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

 

Example 1:

Input: [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
Example 2:



Input: [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
Example 3:

Input: [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
 

Note:

3 <= A.length <= 50
1 <= A[i] <= 100

*/

//CODE

//THIS PROBLEM IS BASICALLY THE MCM PROBLEM OF MIN NO OF MULTIPLICATIONS.
// SAME APPROACH HAS BEEN USED HERE.

class Solution {
public:
    int memo[52][52];
    
    int solve(vector<int> &A, int i, int j)
    {
        if( i >= j)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        int min = INT_MAX;
    for(int k = i; k < j;k++)
    {
        int temp = solve(A,i,k) + solve(A,k+1,j) + (A[i-1] * A[k] * A[j]);
        if(temp < min)
            min = temp;
    }
    return memo[i][j] =  min;
    }
    int minScoreTriangulation(vector<int>& A) {
        memset(memo,-1,sizeof(memo));
        return solve(A,1,A.size()-1);
    }
};