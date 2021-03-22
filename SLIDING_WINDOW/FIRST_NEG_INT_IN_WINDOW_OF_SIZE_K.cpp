/*

Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains an integer n denoting the size of the array. The next line contains n space separated integers forming the array. 
The last line contains the window size k.

Output:
For each testacase, in a new line, print the space separated negative integer starting from the first till the end for every window size k. 
If a window does not contain a negative integer , then print 0 for that window.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=k<=n

Example:

Input:
2
5
-8 2 3 -6 10
2
8
12 -1 -7 8 -15 30 16 28
3

Output:
-8 0 -6 -6
-1 -1 -7 -15 -15 0 
Explanation: For the first subarray, there is -8.
For the second subarray there is no negative element, so the answer is zero. Similiarly, the answer is -6 for the next two subarrays.

*/

//CODE


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> v;
	    for(int i = 0; i < n ; i++)
	    {
	        int x;
	        cin>>x;
	        v.push_back(x);
	    }
	    int k;
	    cin>>k;
	    
	    int i = 0;
	    int j = 0;
	    vector<int> res;
	    queue<int> q;
	    
	    while(j < n)
	    {
	        if(v[j] < 0)
	        q.push(v[j]);
	        
	        if(j - i + 1 < k)
	          j++;
	          
	        else if(j - i + 1 == k)
	        {
	            if(q.size() == 0)
	            res.push_back(0);
	            
	            else
	            {
	                res.push_back(q.front());
	                
	                if(v[i] == q.front())
	                q.pop();
	            }
	            i++;
	            j++;
	        }
	    }
	    
	    for(int i : res)
	    cout<<i<<" ";
	    cout<<endl;
	}
	return 0;
}