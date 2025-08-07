#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string>zigzag(numRows);

        int i = 0 , row =0;
        bool direction = 1 ;

        while(true){
            if(direction){
                while(row<numRows && i<s.size()){
                    zigzag[row++].push_back(s[i++]);
                    
                }
                row = numRows-2;

            }
            else{
                while(row>=0 && i<s.size()){
                    zigzag[row--].push_back(s[i++]);

                }
                row = 1;
            }
            if(i >= s.size()) break;
            direction = !direction;
        }
        string ans = "";
        for(int i =0 ; i<zigzag.size() ; i++){
            ans += zigzag[i];

        }
        return ans;
        
    }
};

// this can not be optimised and has O(n) time complexity and O(n) space complexity













// class Solution {
//     public String convert(String s, int numRows) {
//         if (numRows == 1) return s;

//         StringBuilder[] zigzag = new StringBuilder[numRows];
//         for (int i = 0; i < numRows; i++) {
//             zigzag[i] = new StringBuilder();
//         }

//         int i = 0, row = 0;
//         boolean direction = true; // true = down, false = up

//         while (i < s.length()) {
//             if (direction) {
//                 while (row < numRows && i < s.length()) {
//                     zigzag[row++].append(s.charAt(i++));
//                 }
//                 row = numRows - 2;
//             } else {
//                 while (row >= 0 && i < s.length()) {
//                     zigzag[row--].append(s.charAt(i++));
//                 }
//                 row = 1;
//             }
//             direction = !direction;
//         }

//         StringBuilder result = new StringBuilder();
//         for (StringBuilder sb : zigzag) {
//             result.append(sb);
//         }

//         return result.toString();
//     }
// }
