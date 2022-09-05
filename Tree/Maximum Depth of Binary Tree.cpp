https://leetcode.com/problems/maximum-depth-of-binary-tree/

BFS - 
  
int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        int level = 0;
        
        if(!root)
            return level;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            level++;
        }
        
        return level;
    }

DFS - 
  
  int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        
        return 1+max(x, y);
    }
