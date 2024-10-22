/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here  
        if(!head) return ;
        Node* it = head ;
        for(int i = 0 ; i < M-1 ; i++){
            if(!it) return ;
            it = it -> next ;
            
        }
        
        if(!it) return ;
        
        Node*Mthnode = it ;
        it = Mthnode -> next ;
        
        for(int i = 0 ; i < N ;++i){
            if(!it) break ;
            
            Node*temp = it ->  next ;
            delete it ;
            it = temp ;
            
        }
        Mthnode -> next = it ;
        linkdelete(it ,M,N);
    }
};
