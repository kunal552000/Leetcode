/*

Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, 
and the floor is the greatest element smaller than or equal to x. Assume than the array is sorted in non-decreasing order.

*/

//CODE

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find

    int res = -1;
    int findCeil(vector<long long> v, long long n, long long x){
        
        
        int start = 0;
        int end = n-1;
        
        while(start <= end)
        {
            int mid = start + ((end - start)/2);
            
            if(v[mid] == x)
            return mid;
            
            else if(v[mid] < x)
                start = mid + 1;
                
            

            else
	    {
		res = mid;
                end = mid - 1;
	    }
            
        }
        return res;
        
    }
};