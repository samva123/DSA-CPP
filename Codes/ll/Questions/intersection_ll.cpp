#include <bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            unordered_map<ListNode*,int>mpp;
    for (auto p = headA ; p!=NULL ; p = p->next){
        mpp[p]=p->val;
    }
    for (auto p = headB ; p!=NULL ; p = p->next){
        if (mpp.find(p)!=mpp.end()) return p;
    }
    return NULL;
        
    }
};


// above and below approach both has n+m time but above approach 
//has n space but below approach has 1 space 


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *p1 = headA;
        ListNode *p2 = headB;

        // Traverse both lists
        while (p1 != p2) {
            // Move to the next node or reset to the other list's head
            p1 = (p1 == NULL) ? headB : p1->next;
            p2 = (p2 == NULL) ? headA : p2->next;
        }

        // Either both are NULL (no intersection) or they meet at the intersection
        return p1;
    }
};
