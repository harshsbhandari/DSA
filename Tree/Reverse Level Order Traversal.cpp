https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1?page=1&company[]=Cisco&sortBy=submissions

vector<int> reverseLevelOrder(Node *root){
    // code here
    vector<int>v;
    queue<Node*>q;
    
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        v.push_back(temp->data);
        
        if(temp->right != NULL)
            q.push(temp->right);
            
        if(temp->left != NULL)
            q.push(temp->left);
    }
    reverse(v.begin(), v.end());
    
    return v;
}
