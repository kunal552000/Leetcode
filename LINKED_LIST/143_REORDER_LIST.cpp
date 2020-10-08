/*

Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return ;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = head;
        ListNode* r = head;
        while(slow && fast && fast->next){
            r = slow;
            slow = slow->next;                 //SLOW FAST POINTERS TO FIND MID VALUE
            fast = fast->next->next;
        }
        r->next = NULL;
        fast = slow->next;
        slow->next = NULL;
        while(fast){
            last = slow;
            slow = fast;
            fast = fast->next;               //REVERSING SECOND HALF OF LIST
            slow->next = last;
        }
        r = head;
        last = head;
         while(r && slow)
    {
        last=r;
        r=r->next;
        last->next=slow;
        last=slow;                         //MERGING BOTH SUBLISTS
        slow=slow->next;
        last->next=r;
    }
        if(slow && !r)
    {
        last->next=slow;
    }
    else if(r && !slow) 
    last->next=r;
    
        
        
    }
};