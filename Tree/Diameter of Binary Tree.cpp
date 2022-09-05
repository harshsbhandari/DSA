https://leetcode.com/problems/diameter-of-binary-tree/

int height(TreeNode* root, int& diameter){
        if(!root)
            return 0;
        
        int leftlength = height(root->left, diameter);
        int rightlength = height(root->right, diameter);
        
        diameter = max(diameter, leftlength+rightlength);
        
        return 1+max(leftlength, rightlength);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter); 
        
        return diameter;
    }
