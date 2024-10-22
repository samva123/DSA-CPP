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
    Node* copyRandomList(Node* head) {
        if(!head) return 0;

        Node*it = head;
        while(it){
            Node*clonednode = new Node(it->val);
            clonednode->next = it->next;
            it->next = clonednode;
            it = it->next->next;

        }

        it = head;
        while(it){
            Node*clonednode = it->next;
            clonednode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;

        }

        it = head;
        Node*clonedhead = it->next;
        while(it){
            Node*clonednode = it->next;
            it->next = it->next->next;
            if(clonednode->next){
                clonednode->next = clonednode->next->next;

            }
            it = it->next;
        }
        return clonedhead;
        
    }
};