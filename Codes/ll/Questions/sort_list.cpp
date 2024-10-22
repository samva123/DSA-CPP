class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while (left && right) {
            if (left->val <= right->val) {
                mptr->next = left;
                mptr = left;
                left = left->next;
            } else {
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }

        while (left) {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }

        while (right) {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }

        return ans->next;
    }

    ListNode* FindMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // To keep track of the node before mid

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the right half
        if (prev) {
            prev->next = nullptr;  // This will break the link between left and right halves
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = FindMid(head);   // mid is the start of the right half
        ListNode* left = head;
        ListNode* right = mid;

        left = sortList(left);
        right = sortList(right);

        ListNode* mergedLL = merge(left, right);
        return mergedLL;
    }
};
