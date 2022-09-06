https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

BFS - 
  
vector<int> leftView(Node *root){
    // Your code here
   
    vector<int>ans;
    
    if(!root)
        return ans;
        
    queue<Node*>q;
    q.push(root);
       
    while(!q.empty()){
        int size = q.size();
       
        for(int i = 1; i <= size; i++){
            Node* temp = q.front();
            q.pop(); 
            
            if(i == 1)
                ans.push_back(temp->data);    
        
            if(temp->left != NULL)
                q.push(temp->left);
           
            if(temp->right != NULL)
                q.push(temp->right);
       }
       
    }
   
    return ans;
}

DFS - 
  
  void fun(vector<int>& ans, int level, Node* root){
    if(root == NULL)
        return ;
    if(level == ans.size())
        ans.push_back(root->data);
    
    fun(ans, level+1, root->left);
    fun(ans, level+1, root->right);
}

vector<int> leftView(Node *root){
    // Your code here
   
    vector<int>ans;
    
    if(!root)
        return ans;
        
    int level = 0;
    
    fun(ans, level, root);    
    
    return ans;
}

  
  
