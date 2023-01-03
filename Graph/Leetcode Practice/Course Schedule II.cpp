https://leetcode.com/problems/course-schedule-ii/description/

vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int n = numCourses;
        vector<int>ans, indegree(n, 0);
        vector<int>revadj[n];
        
        for(auto i : prereq){
            int u = i[0], v = i[1];
        
            revadj[v].push_back(u);
        }
        
        queue<int>q;
        
        for(int it = 0; it < n; it++){
	        for(auto i : revadj[it])
	            indegree[i]++;
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
            
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto i : revadj[node]){
                indegree[i]--;
                
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        
        if(ans.size() != n)
            ans.clear();
        
        return ans;
    }
