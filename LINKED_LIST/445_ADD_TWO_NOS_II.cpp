/*

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each 
of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.


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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* first,*second,*third;
        first = head;
        second = NULL;
        third = NULL;
        
        while(first)
        {
            third = second;
            second = first;
            first = first->next;
            
            second->next = third;
        }
        
       
        return second;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        ListNode* l1dash = reverse(l1);
        ListNode* l2dash = reverse(l2);
        
        int carry = 0;
        
        ListNode* newh = new ListNode(-1);
        ListNode* h1 = newh;
        
        while(l1dash || l2dash || carry)
        {
            int sum = 0;
            if(l1dash)
            {
                sum = sum + l1dash->val;
                l1dash = l1dash->next;
            }
            
            if(l2dash)
            {
                sum = sum + l2dash->val;
                l2dash = l2dash->next;
            }
            
            sum = sum + carry;
            carry = sum/10;
            
            ListNode* node = new ListNode(sum%10);
            h1->next = node;
            h1 = h1->next;
            
        }
        
        ListNode* finalh = newh->next;
        delete(newh);
        
        ListNode* ans = reverse(finalh);
        
        return ans;
        
    }
};