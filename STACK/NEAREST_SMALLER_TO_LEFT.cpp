/*

Given an array of integers, find the closest (not considering distance, but value) smaller on left of every element. 
If an element has no smaller on the left side, print -1.

*/

//CODE

#include<bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> s;
    for(int i = 0;i<n;i++)
    {
        if(s.empty())
        ans.push_back(-1);
        
        else if(!s.empty() && s.top() < arr[i])
        ans.push_back(s.top());
        
        else if(!s.empty() && s.top() >= arr[i])
         {
             while(!s.empty() && s.top() >= arr[i])
             s.pop();
             
             if(s.empty())
             ans.push_back(-1);
             
             else
             ans.push_back(s.top());
         }
         
         s.push(arr[i]);
    }
    return ans;
    
}
int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the elements"<<endl;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<int>res = NSL(arr,n);
    cout<<"Resultant vector is :"<<endl;
    for(int i = 0; i <n; i++)
    cout<<res[i]<<" ";
}