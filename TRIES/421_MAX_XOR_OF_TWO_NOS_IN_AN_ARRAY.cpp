/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 = ai < 231.

Find the maximum result of ai XOR aj, where 0 = i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.


*/



//CODE


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
         int maxx = 0, mask = 0;

    set<int> se;

    for (int i = 30; i >= 0; i--) {

        // set the i'th bit in mask
        // like 100000, 110000, 111000..
        mask |= (1 << i);

        for (int i = 0; i < n; ++i) {

            // Just keep the prefix till
            // i'th bit neglecting all
            // the bit's after i'th bit
            se.insert(nums[i] & mask);
        }

        int newMaxx = maxx | (1 << i);

        for (int prefix : se) {

            // find two pair in set
            // such that a^b = newMaxx
            // which is the highest
            // possible bit can be obtained
            if (se.count(newMaxx ^ prefix)) {
                maxx = newMaxx;
                break;
            }
        }

        // clear the set for next
        // iteration
        se.clear();
    }

    return maxx;


        
    }
};