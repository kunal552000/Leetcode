/*

Given two sorted arrays nums1 and nums2 of size m and n respectively.

Return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1,length == m
nums2,length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000

*/

//CODE

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
    	int m = nums2.size();
    	int left = (n + m + 1) / 2;
    	int right = (n + m + 2) / 2;
    	return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
        
    }
    
    
    
      int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
    	int len1 = end1 - start1 + 1;
    	int len2 = end2 - start2 + 1;
    	if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
    	if (len1 == 0) return nums2[start2 + k - 1];
    	if (k == 1) return min(nums1[start1], nums2[start2]);
    	
    	int i = start1 + min(len1, k / 2) - 1;
    	int j = start2 + min(len2, k / 2) - 1;
    	//Eliminate half of the elements from one of the smaller arrays
    	if (nums1[i] > nums2[j]) {
    		return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
    	}
    	else {
    		return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    	}
     }
};