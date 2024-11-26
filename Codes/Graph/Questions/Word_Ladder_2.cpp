//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        queue<pair<vector<string>,int>>q;
        q.push({{beginWord} , 1});
        unordered_set<string> st(wordList.begin() , wordList.end());
        
        int prelevel = -1;
        vector<string>toberemoved;
        
        while(!q.empty()){
            auto fnode = q.front();
            q.pop();
            
            auto currseq = fnode.first;
            auto currstring = currseq[currseq.size()-1];
            auto currlevel = fnode.second;
            
            if(currlevel != prelevel){
                for(auto s:toberemoved) st.erase(s);
                toberemoved.clear();
                prelevel = currlevel;
            }
            
            if(currstring == endWord){
                ans.push_back(currseq);}
                
                
            for(int index = 0 ; index < currstring.length() ; index++){
                char original = currstring[index];
                    
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    currstring[index] = ch;
                        
                    if(st.find(currstring) != st.end()){
                        auto temp = currseq;
                        temp.push_back(currstring);
                        q.push({temp , currlevel+1});
                        toberemoved.push_back(currstring);
                    }
                }
                currstring[index] = original;
            }
        }
        return ans;
        
        
    }
};