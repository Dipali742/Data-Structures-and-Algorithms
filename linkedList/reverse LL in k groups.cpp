class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextn = NULL;
        while(curr != NULL) {
            nextn = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextn;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (head) {
            ListNode* group_start = head;
            ListNode* group_end = head;
            
            // Move group_end to the end of the current group
            for (int i = 1; i < k && group_end; ++i) {
                group_end = group_end->next;
            }
            
            if (!group_end) break; // Less than k nodes left
            
            ListNode* next_group_start = group_end->next;
            group_end->next = NULL; // Break the group
            
            prev->next = reverse(group_start); // Reverse the group
            
            // Update pointers for next iteration
            group_start->next = next_group_start;
            prev = group_start;
            head = next_group_start;
        }
        
        return dummy->next;
    }
};
