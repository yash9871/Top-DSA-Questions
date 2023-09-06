/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void makeLL(Node* &head , Node* &tail , int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* tail = NULL;
        Node* temp = head;
        while(temp) {
            makeLL(cloneHead,tail,temp->val);
            temp = temp->next;
        }

        temp = head;
        Node* ans = cloneHead;
        unordered_map<Node*,Node*> mpp;
        while(temp) {
            mpp[temp] = cloneHead;
            temp = temp->next;
            cloneHead = cloneHead->next;
        }
        temp = head;
        cloneHead = ans;
        while(temp) {
            cloneHead->random = mpp[temp->random];
            cloneHead = cloneHead->next;
            temp = temp->next;
        }
        return ans;
    }
};