//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node*makenodetoparentandfindtarget(Node* root , unordered_map<Node* , Node*>&parentmap , int target ){
        queue<Node*>q;
        Node*targetnode = 0;
        q.push(root);
        parentmap[root] = 0;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data == target){
                targetnode =  front;
            } 
            if(front->left){
                q.push(front->left);
                parentmap[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                parentmap[front->right] = front;
            }
        }
        return targetnode;
    }
    
    int burn(Node*targetnode , unordered_map<Node* , Node*>&parentmap){
        unordered_map<Node* , bool>isburnt;
        queue<Node*>q; // currently on fire
        int T = 0 ;
        q.push(targetnode);
        isburnt[targetnode] = 1;
        while(!q.empty()){
            int size = q.size();
            bool isfirespread = 0;
            for(int i = 0 ; i < size ; ++i){
                Node*front = q.front();
                q.pop();
                if(front->left && !isburnt[front->left]){
                    q.push(front->left);
                    isburnt[front->left] = 1;
                    isfirespread = 1;
                }
                if(front->right && !isburnt[front->right]){
                    q.push(front->right);
                    isburnt[front->right] = 1;
                    isfirespread = 1;
                }
                if(parentmap[front] && !isburnt[parentmap[front]]){
                    q.push(parentmap[front]);
                    isburnt[parentmap[front]] =1;
                    isfirespread = 1;
                }
            }
            if(isfirespread) ++T;
        }
        return T;
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node* , Node*>parentmap;
        Node* targetnode = makenodetoparentandfindtarget(root , parentmap , target);
        return burn(targetnode , parentmap);
    }
};