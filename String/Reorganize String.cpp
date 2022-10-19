https://leetcode.com/problems/reorganize-string/

string reorganizeString(string s) {
        vector<int>v(26,0);
        int n = s.length();
        
        for(int i = 0; i < n; i++)
            v[s[i]-'a']++;
        
        int maxf = *max_element(v.begin(), v.end());
        char maxc = (max_element(v.begin(), v.end()) - v.begin()) + 'a';
        
        if(maxf > (n+1)/2)
            return "";
        
        string res(n,' ');
        int i = 0;
        
        while(maxf){
            res[i] = maxc;
            i += 2;
            maxf--;
        }
        
        v[maxc-'a'] = 0;
        
        for(int j = 0; j < 26; j++){
            while(v[j] > 0){
                i = ((i >= n) ? 1 : i);
                res[i] = (j+'a');
                i += 2;
                v[j]--;
            }
        }
        
        return res;
    }
