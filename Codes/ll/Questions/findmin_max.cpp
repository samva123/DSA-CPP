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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        head = head->next;
        int i = 1, mindist = INT_MAX, prev_i = INT_MIN, first_i = -1;

        while (head != nullptr && head->next != nullptr) {
            if ((prev->val < head->val && head->val > head->next->val) || 
                (prev->val > head->val && head->val < head->next->val)) {
                if (prev_i != INT_MIN) {
                    mindist = min(mindist, i - prev_i);
                }
                if (first_i == -1) {
                    first_i = i;
                }
                prev_i = i;
            }
            prev = head;
            head = head->next;  // Advance the head pointer
            i++;
        }

        if (mindist == INT_MAX) {
            return {-1, -1};
        }

        return {mindist, prev_i - first_i};

        
    }
};


// e and Space Complexity Analysis:
// Time Complexity:
// O(n), where n is the number of nodes in the linked list.
// The while loop iterates through the entire list once, checking for critical points (local maxima and minima), and performing constant-time operations inside the loop.
// Space Complexity:
// O(1), because we're only using a constant amount of extra space (for variables like i, mindist, prev_i, first_i, etc.), irrespective of the input size.