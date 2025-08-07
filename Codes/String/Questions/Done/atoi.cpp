#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int num = 0 , i = 0 , sign = 1 ;//+ve
        while(s[i] == ' '){
            i++;
        }
        if(i<s.size() && (s[i] == '-' || s[i] == '+')){
            sign = s[i] == '+' ? 1: -1;
            ++i;
        }

        while(i<s.size() && isdigit(s[i])){
            if(num > INT_MAX/10 || (num == INT_MAX /10 && s[i] > '7')){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num*10 + (s[i] - '0');
            ++i;


        }
        return num*sign;


        
    }
};
// time is O(n) and space is O(1)





// public class Solution {
//     public int myAtoi(String s) {
//         int num = 0, i = 0, sign = 1;
//         int n = s.length();

//         // Skip leading spaces
//         while (i < n && s.charAt(i) == ' ') {
//             i++;
//         }

//         // Handle sign
//         if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
//             sign = (s.charAt(i) == '+') ? 1 : -1;
//             i++;
//         }

//         // Convert digits
//         while (i < n && Character.isDigit(s.charAt(i))) {
//             int digit = s.charAt(i) - '0';

//             // Handle overflow
//             if (num > Integer.MAX_VALUE / 10 || 
//                (num == Integer.MAX_VALUE / 10 && digit > 7)) {
//                 return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
//             }

//             num = num * 10 + digit;
//             i++;
//         }

//         return num * sign;
//     }

//     public static void main(String[] args) {
//         Solution sol = new Solution();
//         System.out.println(sol.myAtoi("   -42"));      // Output: -42
//         System.out.println(sol.myAtoi("4193 with"));   // Output: 4193
//         System.out.println(sol.myAtoi("words 987"));   // Output: 0
//         System.out.println(sol.myAtoi("-91283472332")); // Output: -2147483648 (Integer.MIN_VALUE)
//     }
// }
