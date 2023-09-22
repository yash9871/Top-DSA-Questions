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
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // fast us point pr poch jaye ga jaha se uska distance null(end) se or slow ka distance n se
        // same hoga    
        for(int i = 0 ; i < n ; i++) fast = fast->next;

        // when fast will reach at last index then slow will reach at n-1 index 
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};