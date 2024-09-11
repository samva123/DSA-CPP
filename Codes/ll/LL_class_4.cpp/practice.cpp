#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }

        ~Node() {
          cout << "Destructor called for: " << this->data << endl;
        }

};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                
        }
        else {
            //step1: creatae a node
            Node* newNode = new Node(data);
            //step2: connect woth tail ndoe
            tail->next = newNode;
            //step3: update tail;
            tail = newNode;
        }

}


void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
        }
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;

    }
    return prev;
}

void addOne(Node* &head){
    head = reverse(head);

    int carry = 1;
    Node* temp = head;

    while(temp->next != NULL){
        int totalsum = temp->data+carry;
        int digit = totalsum%10;
        carry = totalsum/10;

        temp->data = digit;
        temp = temp ->next;
    }

    if(carry != 0){
        int totalsum = temp->data +carry;
        int digit = totalsum%10;
        carry = totalsum/10;

        temp -> data = digit;
        if(carry != 0){
            Node* newnode = new Node(carry);
            temp -> next = newnode;
        }

    }

    head = reverse(head);

}






int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,9);
        insertAtHead(head, tail,9);
        insertAtHead(head, tail,9);
        // insertAtHead(head,tail, 20);
        // insertAtHead(head, tail,10);

        print(head);
        addOne(head);
        cout << endl;
        print(head);
        return 0;
}













































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