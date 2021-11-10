/*


You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that 
is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node 
does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109


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
    
    ListNode* rev(ListNode* head)
    {
        ListNode*first,*second,*third;
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
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> res;
        
        ListNode* newhead = rev(head);
        
        stack<int> s;
        
        while(newhead)
        {
            if(s.empty())
                res.push_back(0);
            
            else if(!s.empty() && s.top() > newhead->val)
                res.push_back(s.top());
            
            else if(!s.empty() && s.top() <= newhead->val)
            {
                while(!s.empty() && s.top() <= newhead->val)
                    s.pop();
                
                if(s.empty())
                    res.push_back(0);
                
                else
                    res.push_back(s.top());
            }
            
            s.push(newhead->val);
            newhead = newhead->next;
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};