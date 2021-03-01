/*

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/

//CODE

class Solution {
public:
   
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<long long>arr(n);
        for(int i = 0; i < n ; i++)
        {
            arr[i] = heights[i];
        }
        vector<long long> left(n), right(n);
    stack<long long> s; 
    //nsl
    
    for(int i=0;i<n;i++){
        if(s.empty()){
            left[i] = -1;
        }else{
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }else{
                left[i] = s.top();
            }
        }
        s.push(i);
    }
    
    //empty stack 
    while(!s.empty()){
        s.pop();
    }
    
    //nsr 
    int j = 0 ; 
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            right[j++] = n;
        }else{
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                right[j++] = n;
            }else{
                right[j++] = s.top();
            }
        }
        s.push(i);
    }
    
    reverse(right.begin(),right.end());
    
    //calculation of width 
    for(int i=0;i<n;i++){
        left[i] = right[i] - left[i] -1;
    }
    
    long long ans = INT_MIN;
    //calculate getMaxArea
    for(int i=0;i<n;i++){
        long x = left[i] * arr[i];
        if(x>ans){
            ans = x;
        }
     }
     return ans;
    }
    };