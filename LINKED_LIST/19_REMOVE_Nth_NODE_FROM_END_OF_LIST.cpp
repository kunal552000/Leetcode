/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *head1,*head2;
        head1 = head;
        head2 = head;
        while(n-->0){
            head2 = head2->next;
        }
        if(head2==NULL)
            return head->next;
        head2 = head2->next;
        while(head2!=NULL)
        {
            head1 = head1->next;
            head2 = head2->next;
            
        }
        head1->next = head1->next->next;
        return head;
        
    }
};