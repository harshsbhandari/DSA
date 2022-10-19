https://leetcode.com/problems/top-k-frequent-elements/

vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m;
        int n = nums.size();
        priority_queue<pair<int,int>>pq;
        
        for(int i = 0; i < n; i++)
            m[nums[i]]++;
        
        vector<int>v;
        
        for(auto i : m)
            pq.push({i.second, i.first});
        
        for(int i = 0; i < k; i++){
            auto it = pq.top();
            v.push_back(it.second);
            pq.pop();
        }
        
        return v;
    }
