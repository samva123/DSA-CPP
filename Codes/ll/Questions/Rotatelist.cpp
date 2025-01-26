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
    int getLength(ListNode*head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;

        int len  = getLength(head);
        int act = (k%len);
        if(act == 0) return head;
        int newji = len-act-1;
        
        ListNode* newLast = head;

        for(int i = 0; i<newji;i++){
            newLast = newLast->next;

        }
        ListNode*newHead = newLast->next;
        newLast->next = 0;

        ListNode*it = newHead;
        while(it->next){
            it = it->next;
        }
        it->next = head;
        return newHead;





        
    }
};

// both has n time and 1 space 




class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head; // If the list is empty or has only one node
        
        // Find the length of the list and the last node
        ListNode* temp = head;
        int len = 1; // Initialize with 1 because we're already at the head
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        // Make the list circular
        temp->next = head;
        
        // Find the new head position after rotating
        k = k % len; // If k is greater than length, take the modulus
        if (k == 0) {
            temp->next = nullptr; // Break the circular link
            return head;
        }

        // Find the node just before the new head
        ListNode* newLast = head;
        for (int i = 1; i < len - k; ++i) {
            newLast = newLast->next;
        }

        // Set new head and break the circle
        ListNode* newHead = newLast->next;
        newLast->next = nullptr;

        return newHead;
    }
};
