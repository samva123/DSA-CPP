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

// Optimizations and Explanation:
// Your code implements the Merge Sort algorithm for linked lists, which is already quite optimal in terms of time complexity. However, we can make some minor improvements to avoid unnecessary memory allocations and to streamline the merging process.

// Avoid Unnecessary Memory Allocations: Instead of allocating a dummy node at the start of the merge function, we can directly use the first node of the merged list. This will reduce memory usage.

// Tail Call Optimization: The recursive function sortList creates multiple stack frames for each split, which may be a concern if the linked list is very large. Tail call optimization might be achieved through some iterative approaches, but typically in C++, this would require changing the recursion into a loop, which might not make the code significantly simpler for linked lists.

// However, Merge Sort on linked lists is already quite efficient for sorting large datasets, and this is a common approach. The only major concern is the recursive stack depth for large linked lists.

// Time Complexity:
// Finding the Mid: The FindMid function traverses the entire list to find the middle, which takes O(n) time, where n is the number of nodes in the linked list.

// Merge Step: The merge function also processes every node in the list and takes O(n) time to merge the two halves.

// Recursive Splitting: The sorting is done recursively, dividing the list into two halves at each step. The depth of the recursion is O(log n), as the list is halved at each step.

// So, overall, the time complexity is:

// Time Complexity: O(n log n)

// This is the best possible time complexity for comparison-based sorting algorithms like merge sort, and it's optimal for linked lists.

// Space Complexity:
// Recursive Stack Depth: Since each recursive call requires space on the call stack, the depth of recursion is O(log n), where n is the number of nodes in the list (because we split the list in half at each recursive step).

// Merge Operation: The merge function doesn't require extra space beyond the nodes in the list being merged. It performs the merging in-place by adjusting pointers, so its space complexity is O(1).

// So, the total space complexity is:

// Space Complexity: O(log n)

// This is due to the recursion stack. There's no additional memory overhead other than the space required for recursive calls.

// Conclusion:
// Time Complexity: O(n log n) (Optimal for sorting algorithms on linked lists)
// Space Complexity: O(log n) (Due to recursion)
// Overall, your code is already optimal for the given problem, and the time and space complexities are the best achievable for sorting linked lists using a comparison-based algorithm like Merge Sort.