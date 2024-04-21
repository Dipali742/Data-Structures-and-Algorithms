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
    int findLength(ListNode* head) {
        ListNode* fast = head;
        int n = 0;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            n++;
        }
        if(fast == NULL)
            return 2*n;
        else
            return 2*n + 1;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        int n = findLength(head);
        cout<<n<<endl;
        k = k % n;
        if(k == 0)
            return head;
        while(k--) {
            fast = fast->next;
        }
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        head = slow->next;
        slow->next = NULL;
        fast->next = dummy->next;
        return head;
    }
};
