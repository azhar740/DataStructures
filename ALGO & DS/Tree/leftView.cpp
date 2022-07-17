
void leftView(Node *root)
{
    /*
            1
        2       3
    4      5   6    7
                
1 N 2 3 N 4 5 6 7 N
                */
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        root = q.front();
        cout << root->data << " ";
        q.pop();
        while(root != NULL) {
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            root = q.front();
            q.pop();
        }
        q.push(NULL);
    }
}


void rightView(Node *root)
{
    /*
            1
        2       3
    4      5   6    7
                
1 N 2 3 N 4 5 6 7 N
                */
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.front()) {
        root = q.front();
        q.pop();
        while(root != NULL) {
            Node *ans = root;
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            
            root = q.front();
            q.pop();
            if(root == NULL) cout << ans << " ";
        }
        q.push(NULL);
    }
}
 
