class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>ans;
        stack<Node*>sa , sb;
        Node*a = root1 , *b = root2;
        while(a || b || !sa.empty() ||!sb.empty()){
            while(a){
                sa.push(a);
                a = a->left;
            }
            
            while(b){
                sb.push(b);
                b = b->left;
            }
            
            if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)){
                auto atop = sa.top();
                ans.push_back(atop->data);
                sa.pop();
                a = atop->right; 
            }
            else{
                auto btop = sb.top();
                sb.pop();
                ans.push_back(btop->data);
                b = btop->right;
            }
        }
        return ans;
        
        
    }
};















// void inorder(Node* root, vector<int> &res) {
//     if (!root) return;
//     inorder(root->left, res);
//     res.push_back(root->data);
//     inorder(root->right, res);
// }

// vector<int> merge(Node *root1, Node *root2) {
//     vector<int> arr1, arr2;
//     inorder(root1, arr1);
//     inorder(root2, arr2);
    
//     vector<int> result;
//     int i = 0, j = 0;
    
//     while (i < arr1.size() && j < arr2.size()) {
//         if (arr1[i] < arr2[j])
//             result.push_back(arr1[i++]);
//         else
//             result.push_back(arr2[j++]);
//     }
    
//     while (i < arr1.size()) result.push_back(arr1[i++]);
//     while (j < arr2.size()) result.push_back(arr2[j++]);
    
//     return result;
// }
