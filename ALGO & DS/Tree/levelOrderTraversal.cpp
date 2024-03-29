void levelOrder(Node* root)
{

  if(root == NULL) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    root = q.front();
    q.pop();
    cout << root->data << " ";
    if(root->left) q.push(root->left);
    if(root->right) q.push(root->right);
  }
}

void mirror(Node* root) 
{
  //Your code here
  queue<Node *> q;

  if(root==NULL) return;

  q.push(root);

  while(!q.empty()){

      root=q.front();

      q.pop();

      if(root->left) q.push(root->left);
      
      if(root->right) q.push(root->right);
      Node *temp = root->left;
      root->left = root->right;
      root->right = temp;
  }
}
