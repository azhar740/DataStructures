#include <iostream>

using namespace std;


struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

bool isSum(Node* root, int n) {
	if(root == NULL) return 0;
	if(root->left) {
		int x = root->data + root->left->data;
		if(x == n) return true;
	}
	if(root->right) {
		int x = root->data + root->right->data;
		if(x == n) return true;
	}
	return isSum(root->left, n) || isSum(root->right, n);

}

int main()
{
    Node * root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(1);
    cout << isSum(root, 9);
    

    return 0;
}