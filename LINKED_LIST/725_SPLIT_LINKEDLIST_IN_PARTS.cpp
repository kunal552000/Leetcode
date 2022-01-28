/*

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead 
to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater 
than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the 
later parts.
 

Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50


*/


//CODE



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> res;
        if(!head)
        {
            while(k--)
                res.push_back(NULL);
        
            return res;
        }
        
        ListNode* temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        
        
        
        int parts = count/k;
        int more = count%k;
        
        if(count < k)
        {
            ListNode* h = head;
            while(more > 0)
            {
                ListNode* hh = h->next;
                h->next = NULL;
                //hh->next = NULL;
                res.push_back(h);
             if(hh)
               h = hh;
                more--;
            }
            
            int rem = k - count;
            while(rem > 0)
            {
                res.push_back(NULL);
                rem--;
                
            }
            //res.push_back(NULL);
            
            return res;
        }
        
        
        ListNode* nh = head;
        for(int i = 0; i < more; i++)
        {
            ListNode* st = nh;
            int temppart = parts;
            while(temppart--)
            {
                nh = nh->next;
                //temppart--;
                
            }
            
            ListNode* temp = nh->next;
            nh->next = NULL;
           // nh = temp;
            res.push_back(st);
            if(temp)
                nh = temp;
            
        }
        
        for(int i = 0; i < k - more; i++)
        {
            ListNode* st = nh;
            int temppart = parts;
            while(temppart > 1)
            {
                nh = nh->next;
                temppart--;
            }
            
            ListNode* temp = NULL;
            if(nh && nh->next)
             temp = nh->next;
            if(nh)
            nh->next = NULL;
           // nh = temp;
            res.push_back(st);
            if(temp)
                nh = temp;
            
        }
        
        return res;
        
    }
};