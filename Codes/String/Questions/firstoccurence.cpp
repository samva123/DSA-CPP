#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int strStr(string haystack ,string needle){
        int n = haystack.size();
        int m = needle.size();

        for(int i =0 ; i<=n-m ; i++){
            for(int j = 0 ; j<=m ;j++){
                if(needle[j] != haystack[i+j]){
                    break;
                }
                if(j == m-1){
                    return i;
                }

            }
        }
        return -1;
    }

};


//METHOD 2

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=needle.size();
        int len_hay=haystack.size();
        for(int i=0 ; i<=len_hay-len ; i++)
        {
            if(haystack.substr(i,len)==needle)
            return i;
        }
        return -1;
    }
};

// both has n*m time complexity and first one has O(1) space complexity and second one has O(m) space complexity
//abd one more is KMP algo which has O(n+m) time complexity and O(m) space complexity

class Solution {
public:
    void computeLPSArray(string needle, vector<int>& lps) {
        int m = needle.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;

        vector<int> lps(m);
        computeLPSArray(needle, lps);

        int i = 0;
        int j = 0;
        while (i < n) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            } else if (i < n && needle[j] != haystack[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};