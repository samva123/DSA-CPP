class Solution{
  public:
    void fun(Node *root , unordered_map<int , bool>&visited , bool&ans){
        if(root == 0 )return ;
        
        visited[root->data] = 1;
        if(root->left == 0 && root->right == 0){
            int xpl = root->data +1;//xpl means x+1 and xml means x-1
            int xml = root->data -1 == 0 ? root->data :root->data -1;
            if(visited.find(xpl) != visited.end() && visited.find(xml) != visited.end()){
                ans = true;
                return ;
                
            }
            
            
        }
        fun(root->left , visited , ans);
        fun(root->right , visited , ans);
        
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        bool ans = false;
        unordered_map<int , bool>visited;
        fun(root , visited , ans);
        return ans;
    }
};



class Solution {
public:
    bool isDeadEndUtil(Node* root, int min, int max) {
        if (!root) return false;
        
        // If this is a leaf node
        if (!root->left && !root->right) {
            // Check if it is a dead end
            if (min == max) return true;
            else return false;
        }
        
        // Recur for left and right subtrees
        return isDeadEndUtil(root->left, min, root->data - 1) ||
               isDeadEndUtil(root->right, root->data + 1, max);
    }
    
    bool isDeadEnd(Node *root) {
        return isDeadEndUtil(root, 1, INT_MAX);
    }
};



///////////////////////////////Wrote for fun////////////////////////


class Solution {
    public:
        struct NodeState {
            Node* node;
            int minVal;
            int maxVal;
        };
        
        bool isDeadEnd(Node* root) {
            if (!root) return false;
            
            queue<NodeState> q;
            q.push({root, 1, INT_MAX});
            
            while (!q.empty()) {
                NodeState current = q.front();
                q.pop();
                
                Node* currNode = current.node;
                int min = current.minVal;
                int max = current.maxVal;
    
                // If it's a leaf and no more values can be inserted
                if (!currNode->left && !currNode->right && min == max) {
                    return true;
                }
    
                if (currNode->left) {
                    q.push({currNode->left, min, currNode->data - 1});
                }
    
                if (currNode->right) {
                    q.push({currNode->right, currNode->data + 1, max});
                }
            }
            
            return false;
        }
    };
    