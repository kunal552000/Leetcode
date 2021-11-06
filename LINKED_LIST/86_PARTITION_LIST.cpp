/*

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

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
    ListNode* partition(ListNode* head, int x) {
        
        if(!head)
            return NULL;
        
        if(!head->next)
            return head;
        
        ListNode* h1 = new ListNode(-1);
        ListNode* h2 = new ListNode(-1);
        
        ListNode* h1dash = h1;
        ListNode* h2dash = h2;
        
        while(head)
        {
            if(head->val < x)
            {
                h1->next = head;
                head = head->next;
                h1 = h1->next;
            }
            
            else
            {
                h2->next = head;
                head = head->next;
                h2 = h2->next;
            }
        }
        
        if(!h2dash->next)
        {
            h1->next = NULL;
            return h1dash->next;
        }
        
        if(!h1dash->next)
        {
            h2->next = NULL;
            return h2dash->next;
        }
        
        ListNode* h1head = h1dash->next;
        delete(h1dash);
        
        ListNode* h2head  = h2dash->next;
        delete(h2dash);
        
        h1->next = h2head;
        h2->next = NULL;
        
        return h1head;
        
        
    }
};