/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // ListNode* curr = node;
        // while(curr != NULL && curr->next != NULL) { 
        //     curr->val = curr->next->val;
        //     if(curr->next->next == NULL)
        //         curr->next = NULL;
        //     curr = curr->next;;
        // }
        
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
