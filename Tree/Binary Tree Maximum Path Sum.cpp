https://leetcode.com/problems/binary-tree-maximum-path-sum/

int fun(TreeNode* root, int& maxsum){
        if(!root)
            return 0;
        
        int sum1 = max(0, fun(root->left, maxsum));
        int sum2 = max(0, fun(root->right, maxsum));
        
        maxsum = max(maxsum, root->val+(sum1+sum2));
        
        return max(sum1, sum2)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        
        if(!root)
            return 0;
        
        fun(root, maxsum);
        
        return maxsum;
    }
