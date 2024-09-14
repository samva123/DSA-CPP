class Solution {
public:
     
    void createUpdateMapping(string& str) {
        //find mappping
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        //update the string
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    bool isIsomorphic(string s, string t) {
       createUpdateMapping(s);
        createUpdateMapping(t);

        if(s == t){
            return true;
        }
        return false;
        
    }
};