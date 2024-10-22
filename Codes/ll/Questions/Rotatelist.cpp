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