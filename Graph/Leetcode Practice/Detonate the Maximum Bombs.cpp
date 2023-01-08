https://leetcode.com/problems/detonate-the-maximum-bombs/description/

// The check function used to check whether other bomb lies in the current's range or not.
/*
   Make a directed graph using the 'check' function considering every node,
   see how many nodes can be traversed, considering each and every node once, answer is the node which gives access to maximum number of adjacent nodes 
*/

int bfs(vector<int>adj[], int n, int src){
        int count = 0;
        vector<int>vis(n, 0);
        queue<int>q;

        q.push(src);
        vis[src] = 1;
        count++;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                    count++;
                }
            }
        }
        return count;
    }

    bool check(int x1, int y1, int r1, int x2, int y2){
        long long a = (long long)(x1-x2) * (long long)(x1-x2);
        long long b = (long long)(y1-y2) * (long long)(y1-y2);
        long long c = (long long)r1 * (long long)r1;

        if(a+b-c <= 0)
            return true;
        return false;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int>adj[n];

        for(int i = 0; i < n; i++){
            int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0; j < n; j++){
                int x2 = bombs[j][0], y2 = bombs[j][1];
                bool flag = check(x1, y1, r1, x2, y2);

                if(i != j && flag)
                    adj[i].push_back(j);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int src = i;
            int count = bfs(adj, n, src);

            ans = max(ans, count);
        }

        return ans;
    }
