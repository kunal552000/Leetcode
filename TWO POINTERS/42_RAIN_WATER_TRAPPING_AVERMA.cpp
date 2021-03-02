/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

*/

//CODE

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
         vector<int> mxl(n);
         vector<int> mxr(n);
       
        int sum = 0;
        mxl[0] = height[0];
       // int mxleft = arr[0];
        for(int i = 1; i < n; i++)
        {
            mxl[i] = max(mxl[i-1] , height[i]);
        }

        mxr[n-1] = height[n-1];
       // int mxright = arr[n-1];
        for(int i = n-2; i>=0; i--)
        {
            mxr[i] = max(mxr[i+1] , height[i]);
        }

        for(int i = 0; i < n ; i++)
        {
            sum = sum + min(mxr[i],mxl[i]) - height[i];
        }
        return sum;
    }
};