 #include <bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 class compare{
     public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        } 
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        //process first element of every LL
        for(int i=0; i<lists.size(); i++) {
            ListNode* listHead = lists[i];
            if(listHead != NULL) {
                pq.push(listHead);
            }
        }

        ///for new LL
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()) {
            ListNode* topNode = pq.top();
            pq.pop();

            //ye frontNode jo nikali h, 
            //ye hamari first node ho
            if(head == NULL) {
                ///pehli node insert krra hu
                head = topNode;
                tail = topNode;
                if(tail->next != NULL) {
                    pq.push(tail->next);
                }
            }
            else {
                //pehle ke baad me koi node insert krra hu
                tail->next = topNode;
                tail = topNode;
                if(tail->next != NULL) {
                    pq.push(tail->next);
                }
            }
        }

    return head;  
    }
};















//////////////////////////////n*k approach where n is total nodes and k is total list
/////////////////////////////very bad approach just simpler/////////////////////
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }

    // merge k lists one by one
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* ans = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};
