class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node*merge(Node*a , Node*b){
        if(!a) return b;
        if(!b) return a;
        
        Node* ans = 0;
        if(a->data < b->data){
            ans = a;
            a->bottom = merge(a->bottom , b);
        }
        else{
            ans = b;
            b->bottom  = merge(a , b->bottom);
        }
        return ans;
    }
    Node *flatten(Node *root) {
        // Your code here
        if(!root) return 0;
        Node*mergedLL = merge(root , flatten(root->next));
        return mergedLL;
    }
};










#include <queue>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // Min-heap
        }
    };

    Node* flatten(Node* root) {
        if (!root) return nullptr;

        // Min-heap to store the nodes
        priority_queue<Node*, vector<Node*>, Compare> pq;

        // Push the head of each linked list into the min-heap
        Node* temp = root;
        while (temp) {
            pq.push(temp);
            temp = temp->next;
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Extract the smallest element and push its bottom node into the heap
        while (!pq.empty()) {
            Node* smallest = pq.top();
            pq.pop();

            tail->bottom = smallest;
            tail = tail->bottom;

            if (smallest->bottom) {
                pq.push(smallest->bottom);
            }
        }

        return dummy->bottom;
    }
};
