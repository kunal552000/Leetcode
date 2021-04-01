/*

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 104
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 1000

*/

//CODE


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>>res;
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>> maxh;
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                maxh.push({nums1[i] + nums2[j] , {nums1[i], nums2[j]}});
                
                if(maxh.size() > k)
                    maxh.pop();
            }
        }
        
        while(!maxh.empty())
        {
            pair<int,int> p;
            p = maxh.top().second;
            
            ans.push_back(p.first);
            ans.push_back(p.second);
            
            res.push_back(ans);
            
            ans.clear();
            maxh.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};