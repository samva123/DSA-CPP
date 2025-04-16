import java.util.*;


class Node{

    int data;
    Node left ;
    Node right;


    Node(int data){
        this.data  = data;
        this.left  = null ;
        this.right  = null;
    }


}





public class practice{


    public static void preorder(Node root){

        //List<Integer>result =  new ArrayList<>();
        if(root == null){
            return ;
        }

        System.out.println(root.data);
        preorder(root.left);
        preorder(root.right);


        //return result;
    }

    public static void main(String[] args){

        Node root  = new Node(2);
        root.left  = new Node(3);
        root.right = new Node(4);
        root.left.left = new Node(5);
        root.left.right = new Node(7);

        preorder(root);


    }
}