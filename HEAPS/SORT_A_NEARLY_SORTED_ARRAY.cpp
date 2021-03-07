/*

Given an array of n elements, where each element is at most k away from its target position. The task is to print array in sorted form.

Input:
First line consists of T test cases. First line of every test case consists of two integers N and K, 
denoting number of elements in array and at most k positions away from its target position respectively. 
Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N

Example:
Input:
2
3 3
2 1 3
6 3
2 6 3 12 56 8
Output:
1 2 3
2 3 6 8 12 56

*/

//CODE

#include <bits/stdc++.h>
using namespace std;



int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    vector<int>arr;
	   
	    for(int i  =0; i < n ; i++)
	    {
	        int x;
	        cin>>x;
	        arr.push_back(x);
	    }
	    vector<int> res;
    priority_queue<int,vector<int>,greater<int>> minh;
    for(int i = 0; i < n ; i++)
    {
        minh.push(arr[i]);
        
        if(minh.size() > k)
        {
            res.push_back(minh.top());
            minh.pop();
        }
    }
    while(!minh.empty())
    {
        res.push_back(minh.top());
            minh.pop();
    }
	    
	    for(int i = 0; i < n ; i++)
	    cout<<res[i]<<" ";
	    cout<<endl;
	}
	return 0;
}