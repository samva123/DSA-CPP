class Node{
    public:
    int data ; 
    Node*left , *right;
    Node(int val):data(val) , left(0) , right(0){};
    
};
class Solution{
    public:
    Node* insert(Node*root , int val , int&succ){
        if(!root) return new Node(val);
        if(val >= root->data){
            root->right = insert(root->right , val , succ);
        }
        else{
            succ = root->data;
            root->left = insert(root->left , val , succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(arr.size() , -1);
        Node*root = 0 ;
        for(int i = arr.size()-1;i>=0;--i){
            int succ = -1;
            root = insert(root , arr[i] , succ);
            ans[i] = succ ;
        }
        return ans;
        
    }
};


#include <vector>
#include <set>

class Solution {
public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), -1);
        std::set<int> bst;

        for (int i = arr.size() - 1; i >= 0; --i) {
            auto it = bst.upper_bound(arr[i]);
            if (it != bst.end()) {
                ans[i] = *it;
            }
            bst.insert(arr[i]);
        }
        return ans;
    }
};


// import java.util.*;

// class Solution {
//     public List<Integer> findLeastGreater(int[] arr, int n) {
//         List<Integer> ans = new ArrayList<>(Collections.nCopies(n, -1));
//         TreeSet<Integer> bst = new TreeSet<>();

//         for (int i = n - 1; i >= 0; i--) {
//             Integer nextGreater = bst.higher(arr[i]);  // strictly greater

//             if (nextGreater != null) {
//                 ans.set(i, nextGreater);
//             }

//             bst.add(arr[i]);
//         }

//         return ans;
//     }
// }



// Time Complexity
// The time complexity of the provided code is O(N log N), where N is the number of elements in the array. This is because each insertion operation in the BST takes O(log N) time on average, and there are N elements to insert.

// Space Complexity
// The space complexity is O(N) due to the space required for the BST and the result vector.

// Optimality
// The current approach is already quite efficient. However, we can consider using a self-balancing BST like std::set in C++ to ensure that the tree remains balanced, which can help maintain the O(log N) insertion time even in the worst case.

// Optimized Approach Using std::set
// Here is an optimized version of the code using std::set:


// findLeastGreater Function: Finds the least greater element for each element in the array.
// Parameters:
// arr: The input array.
// n: The size of the array.
// Logic:
// Use a std::set to maintain a self-balancing BST.
// Traverse the array from right to left.
// For each element, find the smallest element in the set that is greater than the current element using upper_bound.
// If such an element is found, update the result vector.
// Insert the current element into the set.
// Time and Space Complexity
// Time Complexity: O(N log N), where N is the number of elements in the array.
// Space Complexity: O(N) due to the space required for the std::set and the result vector.
// This approach ensures that the least greater elements are found efficiently with optimal time and space complexity.