#include <iostream>
#include<queue>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insertIntoBST(Node* root, int data) {
	if(root == NULL) {
		root = new Node(data);


		return root;
	}

	//its not the first node
	if(data > root->data) {
		root->right = insertIntoBST( root->right, data);
	}
	else {
		root->left = insertIntoBST( root->left, data);
	}
	return root;
}

void createBST(Node* &root) {
	cout << "Enter data:" << endl;
	int data;
	cin >> data;

	while(data != -1) {
		root = insertIntoBST(root, data);
		cout << "Enter data 35:" << endl;
		cin >> data;
	}
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}

void preorder(Node* root) {
	//NLR
	if(root == NULL)
		return ;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	//LNR
	if(root == NULL)
		return ;
	
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	//LRN
	if(root == NULL)
		return ;
	
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

Node* minValue(Node* root) {
	if(root == NULL) {
		cout << "NO MIN VALUE" << endl;
		return NULL; 
	}
	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* maxValue(Node* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	Node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

bool searchInBST(Node* root, int target) {
	//base case
	if(root == NULL) {
		return false;
	}

	//1 case mujhe solve krna h 
	if(root->data == target ) {
		return true;
	}

	//baaaki recursion sambhal lega 
	//left ya right
	bool leftAns = false;
	bool rightAns = false;
	if(target > root->data) {
		rightAns = searchInBST(root->right, target);
	}
	else {
		leftAns = searchInBST(root->left, target);
	}

	return leftAns || rightAns;


	////////////we can shorten the code 

	// if (target > root->data)
    //     return searchInBST(root->right, target);
    // else
    //     return searchInBST(root->left, target);





	/////////iterative

	// bool searchInBST(Node* root, int target) {
	// 	while (root != NULL) {
	// 		if (root->data == target)
	// 			return true;
	// 		else if (target < root->data)
	// 			root = root->left;
	// 		else
	// 			root = root->right;
	// 	}
	// 	return false;
	// }
	

	
}

Node* deleteFromBST(Node* root, int target) {
	///target ko dhundo
	//target ko delete karo

	if(root == NULL) {
		return NULL;
	}

	if(root->data == target) {
		//ab delete karenge
		//4 cases

		
		if(root->left == NULL && root->right == NULL) {
			//1 case -> leaf node
			delete root;
			return NULL;
		}
		else if(root->left != NULL && root->right == NULL) {
			//2 case -> left non null and right null
			Node* childSubtree = root->left;
			delete root;
			return childSubtree;
		}
		else if(root->left == NULL && root->right != NULL) {
			///3 case -> left me NULL and right NON NULL
			Node* childSubtree = root->right;
			delete root;
			return childSubtree;
		}
		//4 case -> left NON NULL && right NON NULL
		else {
			//a -> left subtree ki max value lao
			Node* maxi = maxValue(root->left);
			//replacement
			root->data = maxi->data;

			//delete actual maxi wali node
			root->left = deleteFromBST(root->left, maxi->data);
			return root;
		}
	}
	else if(root->data > target) {
		//left me chalo
		root->left =  deleteFromBST(root->left,  target);
	}
	else {
		//right me jao
		root->right =  deleteFromBST(root->right, target);
	}
	
	return root;
}

int main() {

	Node* root = NULL;
	createBST(root);

	levelOrderTraversal(root);

	// cout << endl << "Inorder: " ;
	// inorder(root);
	// cout << endl << "Preorder: ";
	// preorder(root);
	// cout << endl << "PostOrder: ";
	// postorder(root);


	// cout << endl;
	// Node* minNode = minValue(root);
	// if(minNode == NULL) {
	// 	cout << "There is no node in tree, so no min value" << endl;
	// }
	// else {
	// 	cout << "Min Value: " << minNode->data << endl;
	// }

	// cout << endl;
	// Node* maxNode = maxValue(root);
	// if(maxNode == NULL) {
	// 	cout << "There is no node in tree, so no max value" << endl;
	// }
	// else {
	// 	cout << "Max Value: " << maxNode->data << endl;
	// }

	// int target ;
	// cout << "Enter the value of target: " << endl;
	// cin >> target;

	// while(target != -1) {
	// 	root = deleteFromBST(root,  target);
	// 	cout << endl << "Printing Level Order Traversal: " << endl;
	// 	levelOrderTraversal(root);

	// 	cout << "Enter the value of target: " << endl;
	// 	cin >> target;
		
	// }

	// int t;
	// cout << "Enter the target: " << endl;
	// cin >> t;

	// while(t != -1) {
	// 	bool ans = searchInBST(root, t);
	// 	if(ans == true) {
	// 		cout << "Found" << endl;
	// 	}
	// 	else {
	// 		cout << "Not Found" << endl;
	// 	}

	// 	cout << "Enter the target: " << endl;
	// 	cin >> t;
		
	// } 



	return 0;
}







































/// the createbst function is chnages because we can not do pss by refrence 
//thing in java and there is also one other way to write that 
//looks more like cpp version





// import java.util.*;

// class Node {
//     int data;
//     Node left;
//     Node right;

//     Node(int value) {
//         this.data = value;
//         this.left = null;
//         this.right = null;
//     }
// }

// public class Main {

//     static Node insertIntoBST(Node root, int data) {
//         if (root == null) {
//             root = new Node(data);
//             return root;
//         }

//         if (data > root.data) {
//             root.right = insertIntoBST(root.right, data);
//         } else {
//             root.left = insertIntoBST(root.left, data);
//         }
//         return root;
//     }

//     static Node createBST() {
//         Scanner sc = new Scanner(System.in);
//         Node root = null;

//         System.out.println("Enter data:");
//         int data = sc.nextInt();

//         while (data != -1) {
//             root = insertIntoBST(root, data);
//             System.out.println("Enter data:");
//             data = sc.nextInt();
//         }
//         return root;
//     }

//     static void levelOrderTraversal(Node root) {
//         if (root == null) return;

//         Queue<Node> q = new LinkedList<>();
//         q.offer(root);
//         q.offer(null);

//         while (!q.isEmpty()) {
//             Node temp = q.poll();

//             if (temp == null) {
//                 System.out.println();
//                 if (!q.isEmpty()) {
//                     q.offer(null);
//                 }
//             } else {
//                 System.out.print(temp.data + " ");
//                 if (temp.left != null) q.offer(temp.left);
//                 if (temp.right != null) q.offer(temp.right);
//             }
//         }
//     }

//     static void preorder(Node root) {
//         if (root == null) return;
//         System.out.print(root.data + " ");
//         preorder(root.left);
//         preorder(root.right);
//     }

//     static void inorder(Node root) {
//         if (root == null) return;
//         inorder(root.left);
//         System.out.print(root.data + " ");
//         inorder(root.right);
//     }

//     static void postorder(Node root) {
//         if (root == null) return;
//         postorder(root.left);
//         postorder(root.right);
//         System.out.print(root.data + " ");
//     }

//     static Node minValue(Node root) {
//         if (root == null) {
//             System.out.println("NO MIN VALUE");
//             return null;
//         }
//         Node temp = root;
//         while (temp.left != null) {
//             temp = temp.left;
//         }
//         return temp;
//     }

//     static Node maxValue(Node root) {
//         if (root == null) return null;
//         Node temp = root;
//         while (temp.right != null) {
//             temp = temp.right;
//         }
//         return temp;
//     }

//     static boolean searchInBST(Node root, int target) {
//         if (root == null) return false;

//         if (root.data == target) return true;

//         if (target > root.data) {
//             return searchInBST(root.right, target);
//         } else {
//             return searchInBST(root.left, target);
//         }
//     }

//     static Node deleteFromBST(Node root, int target) {
//         if (root == null) return null;

//         if (root.data == target) {
//             // Case 1: Leaf node
//             if (root.left == null && root.right == null) {
//                 return null;
//             }
//             // Case 2: Left non-null, right null
//             if (root.left != null && root.right == null) {
//                 return root.left;
//             }
//             // Case 3: Left null, right non-null
//             if (root.left == null && root.right != null) {
//                 return root.right;
//             }
//             // Case 4: Both non-null
//             Node maxi = maxValue(root.left);
//             root.data = maxi.data;
//             root.left = deleteFromBST(root.left, maxi.data);
//         } else if (root.data > target) {
//             root.left = deleteFromBST(root.left, target);
//         } else {
//             root.right = deleteFromBST(root.right, target);
//         }
//         return root;
//     }

//     public static void main(String[] args) {
//         Node root = createBST();
//         System.out.println("Level Order:");
//         levelOrderTraversal(root);

//         // Uncomment for extra functionality
//         // System.out.print("\nInorder: ");
//         // inorder(root);
//         // System.out.print("\nPreorder: ");
//         // preorder(root);
//         // System.out.print("\nPostorder: ");
//         // postorder(root);

//         // Node minNode = minValue(root);
//         // if (minNode != null) System.out.println("\nMin Value: " + minNode.data);

//         // Node maxNode = maxValue(root);
//         // if (maxNode != null) System.out.println("Max Value: " + maxNode.data);

//         // Scanner sc = new Scanner(System.in);
//         // System.out.println("Enter target to search:");
//         // int t = sc.nextInt();
//         // while (t != -1) {
//         //     System.out.println(searchInBST(root, t) ? "Found" : "Not Found");
//         //     t = sc.nextInt();
//         // }

//         // System.out.println("Enter target to delete:");
//         // int target = sc.nextInt();
//         // while (target != -1) {
//         //     root = deleteFromBST(root, target);
//         //     levelOrderTraversal(root);
//         //     target = sc.nextInt();
//         // }
//     }
// }













//the other cersion

// static Node createBST(Node root) {
//     Scanner sc = new Scanner(System.in);
//     System.out.println("Enter data:");
//     int data = sc.nextInt();

//     while (data != -1) {
//         root = insertIntoBST(root, data);
//         System.out.println("Enter data:");
//         data = sc.nextInt();
//     }
//     return root;
// }

// and in main

// Node root = null;
// root = createBST(root);
