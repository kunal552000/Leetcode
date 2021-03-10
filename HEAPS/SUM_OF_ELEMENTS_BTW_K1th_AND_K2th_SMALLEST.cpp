/*

Given an array of integers and two numbers k1 and k2. 
Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. 
It may be assumed that (1 <= k1 < k2 <= n) and all elements of array are distinct.

*/

//CODE

#include<bits/stdc++.h>
using namespace std;

int kthsmallest(vector<int> &arr, int n, int k)
{
    priority_queue<int> maxh;
    for(int i = 0; i < n ; i++)
    {
        maxh.push(arr[i]);
        
        if(maxh.size() > k)
        maxh.pop();
    }
    return maxh.top();
}

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    vector<int> arr;
    for(int i = 0; i  < n ; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k1,k2;
    cin>>k1>>k2;
    int first = kthsmallest(arr,n,k1);
    int second = kthsmallest(arr,n,k2);
    
    int sum = 0;
    
    for(int i = 0; i < n ; i++)
    {
        if(arr[i] > first && arr[i] < second)
        sum = sum + arr[i];
    }
    cout<<sum<<endl;
    return 0;
    
}