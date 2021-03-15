/*

Given a sorted array, find the element in the array which has minimum abs difference with the given number.

*/

//CODE

int mindiffele(arr,n,key)
{
    int start = 0;
    int end = n-1;
    
    while(start <= end)
    {
        int mid = start + ((end - start)/2);
        
        if(arr[mid] == key)
        return arr[mid];  //key found so key returned as min value will be 0
        
        else if(arr[mid] > key)
        end = mid - 1;
        
        else
        start = end + 1;
    }
    
    //if key not found then start will be ceil element to key and end will be on floor element in key
    if(abs(arr[end] - key) > abs(arr[start] - key))
    return arr[start];
    
    return arr[end];
}




