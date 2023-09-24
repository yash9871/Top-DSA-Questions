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
    int length(ListNode* A) {
        int cnt = 0;
        while(A){
            A = A->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head) return NULL;
        if(k == 0) return head;
        int len = length(head);
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* pre = dummy;
        ListNode* cur;
        ListNode* nex;
        
        while(len >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i = 1 ; i < k ; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            len -= k;
            pre = cur;
        }
        return dummy->next;
    }
};