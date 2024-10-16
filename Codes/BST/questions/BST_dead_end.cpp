class Solution{
  public:
    void fun(Node *root , unordered_map<int , bool>&visited , bool&ans){
        if(root == 0 )return ;
        
        visited[root->data] = 1;
        if(root->left == 0 && root->right == 0){
            int xpl = root->data +1;
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