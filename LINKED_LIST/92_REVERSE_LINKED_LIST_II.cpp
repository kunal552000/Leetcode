/*

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *left= head, *right = head, *a = NULL;
        
        while(m > 1)
        {
            a = left; //this will stop before left
            left = left->next;
            
            m--;
        }
        
        while(n > 1)
        {
            right = right->next;
            n--;
        }
        ListNode *last = right->next;
        ListNode *p = left, *q = NULL, *r = NULL;
        while(p != last)   //reversing the req list
        {
            r = q;
            q = p;
            p = p->next;
            
            q->next = r;
        }
       if(a != NULL)
        a->next = q;
        
        left->next = last;
        
        if(a == NULL)
            return q;
        
        return head;
        
    }
};