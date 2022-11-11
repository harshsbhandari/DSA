https://leetcode.com/problems/find-center-of-star-graph/description/

/*
  Node with 'n-1' edges connected to it is our answer.
*/
int findCenter(vector<vector<int>>& edges) {
        set<int>st;

        for(auto i : edges){
            st.insert(i[0]);
            st.insert(i[1]);
        }

        int n = st.size();
        vector<int>adj[n+1];

        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(auto i : st){
            int node = i;
            int size = adj[node].size();

            if(size == n-1)
                return node;
        }

        return 0;
    }
