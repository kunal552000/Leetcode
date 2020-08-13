/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *head = new ListNode(0);
          ListNode *l3 = head;
        int carry = 0;
        while(l1 !=NULL || l2 != NULL)
        {
            int l1_value = (l1 != NULL)? l1->val : 0;
            int l2_value = (l2 != NULL)? l2->val : 0;
            
            int currentsum = l1_value + l2_value + carry;
            carry = currentsum/10;
            int lastdig = currentsum%10;
            
            ListNode *newnode = new ListNode(lastdig);
            l3->next = newnode;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
            l3 = l3->next;
            
            
        }
        if(carry>0)
        {
        ListNode *newnode = new ListNode(carry);
            l3->next = newnode;
            l3 = l3->next;
                
        }
        return head->next;
        
        
    }
};