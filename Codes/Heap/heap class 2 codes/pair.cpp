#include <iostream>
using namespace std ;

class info{
    public :
    int maxval;
    bool isheap;

    info(int a , bool b){
        this -> maxval = a ;
        this -> isheap =b ;

    }
    
};

info checkmax(node* root){
    if(root == NULL){
        info temp ;
        temp .maxval = INT_MIN ;
        temp.isheap = true ;
        return temp;
    }
    if(root -> left == NULL && root -> right == NULL){
        info temp ;
        temp.maxval = root -> data ;
        temp.isheap = true ;
        return temp ;
    }
    info leftans = checkmax(root -> left);
    info rightans = checkmax(root -> right);

    if(root -> data > leftans.maxval && root -> data > rightans.maxval &&
    leftans.isheap && rightans.isheap){
        info ans ;
        ans.maxval = root ->data;
        ans.isheap = true ;
        return ans ;
    }
    else{
        info ans ;
        ans.maxval = max(root -> data , max(leftans.maxval , rightans.maxval));
        ans.isheaap = false;
        return ans;
    }
}