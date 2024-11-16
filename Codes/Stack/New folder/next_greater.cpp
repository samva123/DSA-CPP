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
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ll;
        while (head)
        {
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        vector<int> ans(ll.size());

        for (int i = 0; i < ll.size(); ++i)
        { 
            while (!st.empty() && ll[i] > ll[st.top()])
            {
                int kids = st.top();
                st.pop();
                ans[kids] = ll[i];
            }
            st.push(i);
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>>st;

        vector<int>ans;

        int i  = 0 ;

        while(head){
            ans.push_back(0);

            while(!st.empty() && st.top().second < head->val){
                auto top = st.top();
                st.pop();
                ans[top.first] = head->val;
            }
            st.push({i++ , head->val});

            head = head->next;
        }
        return ans;
        
    }
};






// ### Time Complexity
// - **First Approach**: The time complexity is O(n), where n is the number of nodes in the linked list. This is because each node is processed exactly once, and each node can be pushed and popped from the stack at most once.
// - **Second Approach**: The time complexity is also O(n) for the same reasons as the first approach.

// ### Space Complexity
// - **First Approach**: The space complexity is O(n) due to the vector `ll` storing all node values, the vector 
//ans storing the results, and the stack st

//  storing indices.
// - **Second Approach**: The space complexity is O(n) due to the vector 
// ans storing the results and the stack st storing pairs of indices and values.

// ### Differences and General Preference
// 1. **Intermediate Vector**:
//    - **First Approach**: Uses an intermediate vector `ll` to store the values of the linked list. This adds an extra O(n) space overhead.
//    - **Second Approach**: Directly processes the linked list without creating an intermediate vector, which is more space-efficient.

// 2. **Stack Content**:
//    - **First Approach**: The stack stores indices of the vector `ll`.
//    - **Second Approach**: The stack stores pairs of indices and values, which can be slightly more space-consuming but avoids the need for an intermediate vector.

// 3. **Initialization**:
//    - **First Approach**: Initializes the  ans

//  vector with zeros in one go.
//    - **Second Approach**: Pushes zeros into the  ans vector during the traversal of the linked list.

// ### General Preference
// The **second approach** is generally better because:
// - It avoids the extra space overhead of creating an intermediate vector.
// - It directly processes the linked list, which can be more intuitive and straightforward.
// - Both approaches have the same time complexity, but the second approach is slightly more space-efficient.

// ### Conclusion
// Both approaches are efficient with O(n) time complexity and O(n) space complexity. However, the second approach is generally preferred due to its direct processing of the linked list and avoidance of an intermediate vector, making it slightly more space-efficient and straightforward.

// Similar code found with 1 license type