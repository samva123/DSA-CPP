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
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        int len = findLength(head);
        
        if(position == 1) {
                insertAtHead(head, tail , data);
                return;
        }
        else if(position > len) {
                insertAtTail(head, tail, data);
                return;
        }
        else {
            Node* newNode = new Node(data);
            
            Node* prev = NULL;
            Node* curr = head;
            while(position != 1) {
                position--;
                prev = curr;
                curr = curr->next;
            }
            
            //step3:
            newNode -> next = curr;

            //step4:
            prev -> next = newNode;
            
        }
        
}


Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        

        while(curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    
    
void adddOne(Node * &head){
    head = reverse(head);
    
    
    int carry = 1;
    Node *temp = head;
    
    while(temp->next != NULL){
        int sum = temp->data + carry;
        int digit = sum%10;
        carry = sum/10;
        
        temp-> data = digit;
        temp = temp->next;
        if(carry == 0){
            break; 
        }
        
    }
        


  if(carry != 0){
      int sum = temp->data + carry;
        int digit = sum%10;
        carry = sum/10;
        
        temp-> data = digit;
        if(carry != 0){
            Node* newnode = new Node(carry);
            temp->next = newnode;
        }
  }
  
  head = reverse(head);

}


int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,8);
        insertAtHead(head, tail,3);
        insertAtHead(head, tail,1);
        // insertAtHead(head,tail, 90);
        // insertAtTail(head, tail, 77);

        // for loops questions 
        // tail->next = head->next->next;

        print(head);
        
        // head = reverse(head);
        cout << endl;
        
        // print(head);
        // cout << endl;
        
        adddOne(head);
        print(head);
        cout<<endl;

        return 0;
}