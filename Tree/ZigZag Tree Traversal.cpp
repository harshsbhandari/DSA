https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?page=1&company[]=Cisco&sortBy=submissions

vector <int> zigZagTraversal(Node* root){
    	// Code here
    	queue<Node*>q;
    	vector<int>v;
    	int count=0;
    	
    	q.push(root);
    	
    	bool flag = true;
    	
    	while(!q.empty()){
    	    vector<int>temp;
    	    int size = q.size();
    	    
    	    for(int i = 0; i < size; i++){
    	        Node* node = q.front();
    	        q.pop();
    	        temp.push_back(node->data);
    	        
    	        if(node->left != NULL)
    	            q.push(node->left);
    	            
                if(node->right != NULL)
    	            q.push(node->right);
    	    }
    	    flag = !flag;
    	    
    	    if(flag)
    	        reverse(temp.begin(), temp.end());
    	    
    	    for(int i = 0; i < size;i++)
    	        v.push_back(temp[i]);
    	}
    	
    	
    	return v;
    }
