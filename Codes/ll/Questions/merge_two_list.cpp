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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(left == 0) return right;
        if(right == 0) return left;

        ListNode*ans  = new ListNode(-1);
        ListNode*mptr = ans;

        while(left && right){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;

            }
            else{
                mptr->next = right;
                mptr=right;
                right=right->next;
            }
        }

        while(left){
            mptr->next = left;
            mptr = left;
            left = left->next;
        }


        while(right){
            mptr->next = right;
            mptr = right;
            right = right->next;
        }

        return ans->next;


        
    }
};


// below is the same code with time n+m and 
// 1 as space just another way to write 


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        // Create a dummy node to act as the head of the merged list
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        // Merge the two lists
        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // Attach the remaining nodes (if any) from the non-empty list
        tail->next = left ? left : right;

        return dummy.next;
    }
};
