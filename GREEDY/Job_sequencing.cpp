/*

Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to 
complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. 
The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an 
integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500

*/


class Solution 
{
    public:
    
    
    static bool compare( Job m1, Job m2)
    {
        return m1.profit>m2.profit;
    } 
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        
        
       sort(arr, arr + n, compare);
        
        int maxi = arr[0].dead;
        for(int i = 1; i < n; i++)
            maxi = max(maxi,arr[i].dead);
            
        int slot[maxi+1];
        
        for(int i = 0; i <= maxi; i++)
        slot[i] = -1;
        
        int jobcount = 0;
        int maxprofit = 0;
        
        for(int i = 0; i < n ; i++)
        {
            for(int j = arr[i].dead; j > 0; j--)
            {
                if(slot[j] == -1)
                {
                    slot[j] = i;
                    jobcount++;
                    maxprofit = maxprofit + arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> res(2);
        res[0] = jobcount;
        res[1] = maxprofit;
        
        return res;
    } 
};