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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode*,int>mpp;
        // while(headA) {
        //     mpp[headA]++;
        //     headA = headA->next;
        // }
        // while(headB) {
        //     if(mpp.find(headB) != mpp.end()) return headB;
        //     headB = headB->next;
        // }
        // return NULL;
        
        ListNode * a = headA;
        ListNode * b = headB;
        while(a != b) {
            if(!a) a = headB;
            else if(!b) b = headA;
            else {
                a = a->next;
                b = b->next;
            }
        }
        return a;
    }
};