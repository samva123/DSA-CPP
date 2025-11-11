#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string&s , int start , int end ){
        while(start<end){
            if(s[start] != s[end]){
                return false;
            }
            start++ , end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0 ; i <s.size() ; i++){
            for(int j = i ; j<s.size() ; j++){
                if(isPalindrome(s,i,j)){
                    string t = s.substr(i , j-i+1);
                    ans = t.size() > ans.size() ? t:ans;


                }

            }
        }
        return ans;
        
    }
};







// public class Solution {

//     // Function to check if a substring is a palindrome
//     public boolean isPalindrome(String s, int start, int end) {
//         while (start < end) {
//             if (s.charAt(start) != s.charAt(end)) {
//                 return false;
//             }
//             start++;
//             end--;
//         }
//         return true;
//     }

//     // Function to find the longest palindromic substring
//     public String longestPalindrome(String s) {
//         String ans = "";

//         for (int i = 0; i < s.length(); i++) {
//             for (int j = i; j < s.length(); j++) {
//                 if (isPalindrome(s, i, j)) {
//                     String t = s.substring(i, j + 1);
//                     if (t.length() > ans.length()) {
//                         ans = t;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }

//     // Optional main method to test the function
//     public static void main(String[] args) {
//         Solution sol = new Solution();
//         String input = "babad";
//         System.out.println(sol.longestPalindrome(input));  // Output: "bab" or "aba"
//     }
// }






// public class Solution {
//     public String longestPalindrome(String s) {
//         int n = s.length();
//         if (n == 0) return "";

//         int start = 0, maxLen = 1;

//         for (int i = 0; i < n; i++) {
//             // Odd length palindrome
//             int l = i, r = i;
//             while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
//                 if (r - l + 1 > maxLen) {
//                     start = l;
//                     maxLen = r - l + 1;
//                 }
//                 l--;
//                 r++;
//             }

//             // Even length palindrome
//             l = i;
//             r = i + 1;
//             while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
//                 if (r - l + 1 > maxLen) {
//                     start = l;
//                     maxLen = r - l + 1;
//                 }
//                 l--;
//                 r++;
//             }
//         }

//         return s.substring(start, start + maxLen);
//     }

//     // Optional main method to test the code
//     public static void main(String[] args) {
//         Solution sol = new Solution();
//         String input = "babad";
//         System.out.println(sol.longestPalindrome(input));  // Output: "bab" or "aba"
//     }
// }
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string input = "babad";
    cout << sol.longestPalindrome(input) << endl; // Output: "bab" or "aba"
    return 0;
}
