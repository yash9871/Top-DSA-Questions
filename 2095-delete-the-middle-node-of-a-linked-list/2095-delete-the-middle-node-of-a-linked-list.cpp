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
    ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // if even length toh slow mid se ek point pelhe betha hoga 
    if(fast->next) {
        ListNode* a = slow->next;
        slow->next = slow->next->next;
        a->next = NULL;
        delete a;
    } // if odd length toh slow exactly mid pr betha hoga
    else {
        int a = slow->next->val;
        slow->val = a;
        slow->next = slow->next->next;
    }
    return head;
    }
};