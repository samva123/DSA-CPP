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