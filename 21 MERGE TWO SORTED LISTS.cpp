/*

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        struct ListNode *sorter,*newhead;
        newhead = NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1&&l2)
        {
            if(l1->val <= l2->val)
            {
                sorter = l1;
                l1 = sorter->next;
            }
            else
            {
                sorter = l2;
                l2 = sorter->next;
            }
        }
        newhead = sorter;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                sorter->next = l1;
                sorter = l1;
                l1 = sorter->next;
            }
            else
            {
                sorter->next = l2;
                sorter = l2;
                l2 = sorter->next;
            }
        }
        if(l1 == NULL)
            sorter->next = l2;
        if(l2 == NULL)
            sorter->next = l1;
        return newhead;
        
    }
};