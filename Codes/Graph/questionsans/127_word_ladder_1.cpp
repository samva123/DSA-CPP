#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        
        queue<pair<string,int>>q;
        q.push({{beginWord} , 1});
        unordered_set<string> st(wordList.begin() , wordList.end());
        //add karo or hta do
        st.erase(beginWord);

        while(!q.empty()){
            auto fnode = q.front();
            q.pop();
            
            
            auto currstring = fnode.first;
            auto currlevel = fnode.second;
            
            if(currstring == endWord){
                return currlevel;}
                
                
            for(int index = 0 ; index < currstring.length() ; index++){
                char original = currstring[index];
                    
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    currstring[index] = ch;
                        
                    if(st.find(currstring) != st.end()){
                        
                        q.push({currstring , currlevel+1});
                        st.erase(currstring);
                        
                    }
                }
                currstring[index] = original;
            }
        }
        return 0;
        
    }
};


















































//////////////////////bidirectional bfs///////////////////
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> beginSet, endSet, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> nextSet;
            for (string word : beginSet) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (endSet.count(temp)) return steps + 1;
                        if (dict.count(temp) && !visited.count(temp)) {
                            nextSet.insert(temp);
                            visited.insert(temp);
                        }
                    }
                    temp[i] = original;
                }
            }
            beginSet = nextSet;
            steps++;
        }
        return 0;
    }
};
