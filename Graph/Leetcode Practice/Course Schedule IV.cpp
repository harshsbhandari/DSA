https://leetcode.com/problems/course-schedule-iv/description/

// Check whether from start can we reach the end

bool bfs(int start, int end, int n, vector<int>adj[]){
        queue<int>q;
        vector<int>vis(n, 0);

        q.push(start);
        vis[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == end)
                return true;

            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i] = i;
                    q.push(i);
                }
            }
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<int>adj[n];

        for(auto i : prereq){
            int u = i[0], v = i[1];
            
            adj[u].push_back(v);
        }

        vector<bool>ans;

        for(auto i : queries){
            int u = i[0], v = i[1];
            bool flag = bfs(u, v, n, adj);

            if(flag)
                ans.push_back(true);
            else
                ans.push_back(false); 
        }

        return ans;
    }
