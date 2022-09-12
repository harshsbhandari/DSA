https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

vector<vector<string>> findSequences(string begin, string end, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        set<string>st(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        vector<string>usedOnLevel;
        int level = 0;
        
        usedOnLevel.push_back(begin);
        q.push({begin});
        
        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();
            
            // erase all the words that has benn used in the previous levels to transform
            if(vec.size() > level){
                level++;
                
                for(auto i : usedOnLevel)
                    st.erase(i);
            }
            
            string word = vec.back();
            
            if(word == end){
                if(ans.size() == 0)
                    ans.push_back(vec);
                    
                else if(ans[0].size() == vec.size())
                    ans.push_back(vec);
            }
            
            for(int i = 0; i < word.size(); i++){
                char orig = word[i];
                
                for(char j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = orig;
            }
        }
        
        return ans;
    }
