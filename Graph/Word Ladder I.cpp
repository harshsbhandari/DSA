https://practice.geeksforgeeks.org/problems/word-ladder/1

int wordLadderLength(string start, string target, vector<string>& wordList) {
        // Code here
        set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        
        q.push({start, 1});
        st.erase(start);
        
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(target == word)
                return level;
            
            for(int i = 0; i < word.size(); i++){
                char orig = word[i];
                
                // replacing every character with from 'a' to 'z' and checking whether it exists in the set or not 
                for(char j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    
                    if(st.find(word) != st.end()){
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word[i] = orig;
            }
        }
        
        return 0;
    }
