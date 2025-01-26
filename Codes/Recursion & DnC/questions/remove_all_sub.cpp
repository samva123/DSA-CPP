#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void remove (string &s , string&part){
        int found  = s.find(part);
        if(found != string::npos){

            string left_part =  s.substr(0 , found);
            string right_part = s.substr(found +part.size() , s.size());
            s = left_part + right_part;

            remove(s , part);

        }
        else{
            return ;
        }
    }
    string removeOccurrences(string s, string part) {
        remove(s , part);
        return s ;
        
    }
};