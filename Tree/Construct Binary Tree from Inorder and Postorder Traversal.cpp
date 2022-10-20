https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/

TreeNode* fun(vector<int>& inorder,int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int>& inMap){
        
        if(inStart > inEnd || postStart > postEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = inMap[root->val];
        int numsLeft = inRoot-inStart;
        
        root->left = fun(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1,inMap);
        root->right = fun(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.size() != inorder.size())
            return NULL;
        
        map<int,int>inMap;
        
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        TreeNode* root = fun(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
        
        return root;
    }
