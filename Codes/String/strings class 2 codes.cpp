#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
//1047

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int index = 0;

        while(index < s.length()) {
            //same
            //ans ka rightmost character and string s ka current character
            if(ans.length() > 0 && ans[ans.length()-1] == s[index]) {
                //pop from ans string
                ans.pop_back();
            }
            else {
                //push
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> ans;
        for (char c : s) {
            if (!ans.empty() && ans.back() == c) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return string(ans.begin(), ans.end());
    }
};
 

//https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
//1910

class Solution {
public:
    string removeOccurrences(string s, string part) {
        

        while(s.find(part) != string::npos) {
            //if inside loop, it means that part exists in s string
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};// find has time complexity of n*m and erase has on n and the loop runs n/m times 

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int partLen = part.length();

        for (char c : s) {
            result.push_back(c);
            if (result.size() >= partLen && result.substr(result.size() - partLen) == part) {
                result.erase(result.size() - partLen, partLen);
            }
        }

        return result;
    }
};

// First Solution:
// Time Complexity: O(n^2) where n is the length of the string s
// Space Complexity: O(1)
// Second Solution:
// Time Complexity: O(n * m)
// Space Complexity: O(n)



//https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool checkPalindrome(string s, int i, int j) {
        while( i<= j) {
            if(s[i] != s[j] ) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while( i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else{
                //s[i]!=s[j]
                //1 removal allowed
                //check plaindrome for remaining string after removal

                //ith character -> remove
                bool ans1 = checkPalindrome(s, i+1, j);
                //jth character -> remove
                bool ans2 = checkPalindrome(s, i, j-1);

                return ans1 || ans2;
            }
        }
        //agar yha tk pohoche ho
        //iska matlab valid palindrome hai
        //iska matlab -> 0 removal
        return true;
    }
}; 
//time complexity O(n)




//647  

//https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int expand(string s,int i, int j) {
        int count = 0;

        while(i >= 0 && j < s.length() && s[i] == s[j] ) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int i = 0; i < s.length(); i++ ) {
            //ODD
            int j = i;
            int oddKaAns = expand(s, i, j);  
            //EVEN
            j = i+1;
            int evenKaAns = expand(s, i, j);
            totalCount = totalCount + oddKaAns + evenKaAns;
        }
        return totalCount;
    }
};

// Summary:
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// This approach is already optimal for counting palindromic substrings in a given string.

// string ke andar kuch find karne kee kon kon si algorithm hai or un sab ki time complexity 
// or erase function ki implementation and find function ki bhi time complexity