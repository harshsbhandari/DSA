https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

TreeNode* fun(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap){
        
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[preorder[preStart]];
        int numsLeft = inRoot-inStart;
        
        root->left = fun(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
        root->right = fun(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        TreeNode* root = fun(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        
        return root;
    }
