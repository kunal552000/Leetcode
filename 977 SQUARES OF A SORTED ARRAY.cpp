/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/


//CODE:


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>output(A.size());
        int l =0,r=A.size()-1;
        for(int k=A.size()-1;k>=0;k--)
        {
            if(abs(A[l])>abs(A[r])){
                output[k] = A[l]*A[l];
                l++; 
            }
            else{
                output[k] = A[r]*A[r];
                r--;
            }
        }
        return output;
        
    }
};