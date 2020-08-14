/*

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:



After flattening the multilevel linked list it becomes:


Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL
Example 3:

Input: head = []
Output: []

*/

//CODE

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node *current;
        Node *tail;
        current = head;
        tail = head;
        stack<Node*>s;
        while(current!=NULL)
        {
            if(current->child != NULL){
                Node* child = current->child;
                if(current->next != NULL)
                {
                    s.push(current->next);
                    current->next->prev = NULL;
                }
                current->next = child;
                child->prev = current;
                current->child = NULL;
            }
            tail = current;
            current = current->next;
            
        }
        while(!s.empty()){
            current = s.top();
            s.pop();
            tail->next = current;
            current->prev = tail;
            while(current !=NULL)
            {
                tail = current;
                current = current->next;
            }
        }
        return head;
        
        
    }
};