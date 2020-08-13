/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
         struct ListNode *fast,*slow;
        slow = head;
        fast = head;
        while(fast!= NULL && fast->next!= NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow =   reversed(slow);
        fast = head;
        while(slow!=NULL)
        {
            if(slow->val != fast->val)
                return false;
        
        slow = slow->next;
        fast = fast->next;
        }
        return true;
        
    }
    public:
    ListNode* reversed(ListNode *head)
    {
        struct ListNode *prev,*next;
        prev = NULL;
        while(head!=NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            
        }
        return prev;
    }
    
        
    
};