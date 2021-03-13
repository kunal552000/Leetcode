/*

Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions,
i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. 
Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.

*/

//CODE

#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> &arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    
    while(start <= end)
    {
        int mid = start + ((end - start)/2);
        
        if(arr[mid] == key)
        return mid;
        
        if(mid - 1 >= start && arr[mid - 1] == key)
        return mid-1;
        
        if(mid + 1 <= end && arr[mid + 1] == key)
        return mid + 1;
        
        if(arr[mid] < key)
        start = mid + 2;
        
        else
        end = mid - 2;
    }
    return -1;
}


int main()
{
    int n;
    cout<<"Enter size of Array"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter elements"<<endl;
    for(int i = 0; i < n ; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int key;
    cout<<"Enter key"<<endl;
    cin>>key;
    
    int ans = bs(arr,n,key);
    
    cout<<ans<<endl;
    return 0;
    
}