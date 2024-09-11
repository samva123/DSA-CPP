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
int len(ListNode*head){
    int i=0;
    while(head!=NULL){
        i++;
        head=head->next;
    }
    return i;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)return head;
        if(head->next==NULL)return head;
        if(len(head) < k) return head;
        // 1 case
        // int length=len(head);
        // if(length>=k) return head;
        // ListNode*prev=NULL;
        // ListNode*curr=head;
        // ListNode*nextNode=curr->next;
        // int pos=1;
        // while(pos<k){
     
        //     nextNode=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nextNode;
        //            pos++;
        // }
        //    ListNode*recAns=NULL;
        // if(nextNode!=NULL){
        //     recAns=reverseKGroup(nextNode,k);
        //     nextNode->next=prev;
        // }
        // return recAns;
        ListNode*curr=head;
        int count=0;
        while(curr && count<k){
            curr=curr->next;
            count++;
        }
        if(count<k)return head;
        ListNode*prev=NULL,*nextNode=NULL;
        curr=head;
        for(int i=0;i<k;i++){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};