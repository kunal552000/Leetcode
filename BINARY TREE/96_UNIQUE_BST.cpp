/*


Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

1 <= n <= 19

*/


//CODE

class Solution {
public:
    int numTrees(int n) {
        long long int unique = 1;
        for(int i=1;i<=n;i++){
            unique *= (n+i);
            unique /= i;
        }
        unique /= (n+1);
        return unique;
        
        
    }
};