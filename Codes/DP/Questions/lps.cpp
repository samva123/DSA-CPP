class Solution {
public:
    int maxlen = 1 , start = 0 ;
    bool solve(string&s , int i , int j){
        if(i>=j){
            return true;
        }
        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s, i+1 , j-1);
        }
        if(flag){
            int currlen = j-i+1;
            if(currlen > maxlen){
                maxlen = currlen;
                start = i;
            }
        }
        return flag;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = 0 ; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                bool t = solve(s,i,j);
            }
        }
        return s.substr(start,maxlen);

        
    }
};






///////ISME BOTTOM UP NAHI KARAYA////////////////////