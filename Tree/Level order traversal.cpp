https://practice.geeksforgeeks.org/problems/level-order-traversal/1

vector<int> levelOrder(Node* node){
      //Your code here
      queue<Node*>q;
      q.push(node);
      
      vector<int>v;
      
      while(!q.empty()){
          Node* temp = q.front();
          q.pop();
          
          v.push_back(temp->data);
          
          if(temp->left != NULL)
            q.push(temp->left);
          
          if(temp->right != NULL)
            q.push(temp->right);
      } 
      
      return v;
    }
