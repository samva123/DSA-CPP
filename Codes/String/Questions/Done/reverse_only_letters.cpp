#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0 , h = s.size()-1;
        while(l<h){
            if(isalpha(s[l]) && isalpha(s[h])){
                swap(s[l] , s[h]);
                l++ , h-- ;
            }
            else if(!isalpha(s[l])){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
        
    }
};


// public class Solution {
//     public String reverseOnlyLetters(String s) {
//         char[] arr = s.toCharArray();
//         int l = 0, h = arr.length - 1;

//         while (l < h) {
//             if (Character.isLetter(arr[l]) && Character.isLetter(arr[h])) {
//                 // Swap the letters
//                 char temp = arr[l];
//                 arr[l] = arr[h];
//                 arr[h] = temp;
//                 l++;
//                 h--;
//             } else if (!Character.isLetter(arr[l])) {
//                 l++;
//             } else {
//                 h--;
//             }
//         }

//         return new String(arr);
//     }
// }
