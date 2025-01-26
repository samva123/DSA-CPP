#include <bits/stdc++.h>
using namespace std;
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


// Why This is Already Optimal
// Time Complexity:
// Each node is traversed only a constant number of times (3 passes in total). So, the time complexity is O(n).
// Space Complexity:
// No extra memory is used for hash maps or arrays. The cloning and linking are done within the existing list, so the space complexity is O(1).
// Is There a More Optimized Approach?
// No, there isn't a better solution in terms of time and space complexity. Your solution is state-of-the-art for this problem.