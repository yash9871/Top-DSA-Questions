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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 && !l2) return l1;
        else if(l2 && !l1) return l2;
        else if(!l1 && !l2) return l1;
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* temp = NULL;
        int carry = 0 , n = 0;
        while(l1 && l2) {
            n = l1->val + l2->val+carry;
            if(n > 9) {
                carry = 1;
                temp = new ListNode(n%10);
            }
            else {
                temp = new ListNode(n);
                carry = 0;
            }
            if(head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            n = l1->val+carry;
            if(n > 9) {
                temp = new ListNode(n%10);
                carry = 1;
            }
            else {
                temp = new ListNode(n);
                carry = 0;
            }
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
        }
        while(l2) {
            n = l2->val+carry;
            if(n > 9) {
                temp = new ListNode(n%10);
                carry = 1;
            }
            else {
                temp = new ListNode(n);
                carry = 0;
            }
            tail->next = temp;
            tail = temp;
            l2 = l2->next;
        }
        if(carry) {
            temp = new ListNode(1);
            tail ->next = temp;
        }
        return head;
    }
};