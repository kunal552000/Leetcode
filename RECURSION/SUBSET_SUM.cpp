/*


Given a list arr of N integers, print sums of all subsets in it. Output should be printed in increasing order of sums.

Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
Your Task:  
You don't need to read input or print anything. Your task is to complete the function subsetSums() which takes a list/vector 
and an integer N as an input parameter and return the list/vector of all the subset sums in increasing order.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= arr[i] <= 10000


*/


//CODE


class Solution
{
public:

    
    void solve(int index, int sum, vector<int> &arr, int N, vector<int>& res)
    {
        //base case
        if(index == N)
        {
            res.push_back(sum);
            return;
        }
        

        //if i pick an element
        solve(index+1,sum+arr[index],arr,N,res);
        


        //if i dont pick an element
        solve(index+1, sum,arr,N,res);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int> res;
        solve(0,0,arr,N,res);
        sort(res.begin(),res.end());
        return res;
    }
};
