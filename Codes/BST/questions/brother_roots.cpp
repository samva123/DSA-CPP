class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans = 0 ;
        stack<Node*>s1 , s2;
        Node*a = root1;
        Node*b = root2;
        while(1){
            while(a){
                s1.push(a);
                a=a->left;
            }
            
            while(b){
                s2.push(b);
                b=b->right;
                
            }
            if(s1.empty() || s2.empty()){
                break;
            }
            auto atop = s1.top();
            auto btop = s2.top();
            
            int sum = atop->data + btop->data;
            
            if(sum == x){
                ++ans;
                s1.pop();
                s2.pop();
                a = atop->right;
                b = btop->left;
            }
            else if(sum < x){
                s1.pop();
                a = atop->right;
            }
            else{
                s2.pop();
                b = btop->left;
            }
        }
        return ans;
 
    }
};





    class Solution {
        public:
            void inorder(Node* root, unordered_set<int>& s) {
                if (!root) return;
                inorder(root->left, s);
                s.insert(root->data);
                inorder(root->right, s);
            }
        
            int countPairs(Node* root1, Node* root2, int x) {
                unordered_set<int> s;
                inorder(root1, s);
        
                int count = 0;
                stack<Node*> st;
                Node* curr = root2;
        
                while (curr || !st.empty()) {
                    while (curr) {
                        st.push(curr);
                        curr = curr->left;
                    }
                    curr = st.top(); st.pop();
                    if (s.count(x - curr->data)) ++count;
                    curr = curr->right;
                }
                return count;
            }
        };
        
























        class Solution {
            public:
                void inorder(Node* root, vector<int>& v) {
                    if (!root) return;
                    inorder(root->left, v);
                    v.push_back(root->data);
                    inorder(root->right, v);
                }
            
                int countPairs(Node* root1, Node* root2, int x) {
                    vector<int> v1, v2;
                    inorder(root1, v1);
                    inorder(root2, v2);
            
                    int i = 0, j = v2.size() - 1, count = 0;
                    while (i < v1.size() && j >= 0) {
                        int sum = v1[i] + v2[j];
                        if (sum == x) {
                            ++count;
                            ++i; --j;
                        } else if (sum < x) {
                            ++i;
                        } else {
                            --j;
                        }
                    }
                    return count;
                }
            };
            