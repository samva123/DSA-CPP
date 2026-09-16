#include<bits/stdc++.h>
using namespace std;

///////////////////////////RECURSION////////////////////
class Solution {
public:
    int solve(string&s1 , string&s2,string&s3,int i , int j , int k){
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;

        bool flag = false;

        if(i< s1.size() && s1[i] == s3[k]){
            flag = flag || solve(s1 ,s2 ,s3 ,i+1 , j , k+1);
        }

        if( j < s2.size() && s2[j] == s3[k]){
            flag = flag || solve(s1 ,s2 ,s3 ,i, j+1 , k+1);
        }

        return flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1,s2,s3,0,0,0);

        
    }
};
////////////////MEMO/////////////////////
class Solution {
public:
    int solve(string&s1 , string&s2,string&s3,int i , int j , int k , vector<vector<vector<int>>>&dp){
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool flag = false;

        if(i< s1.size() && s1[i] == s3[k]){
            flag = flag || solve(s1 ,s2 ,s3 ,i+1 , j , k+1,dp);
        }

        if( j < s2.size() && s2[j] == s3[k]){
            flag = flag || solve(s1 ,s2 ,s3 ,i, j+1 , k+1,dp);
        }

        return dp[i][j][k] = flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1 , vector<vector<int>>(s2.size()+1 , vector<int>(s3.size()+1 , -1)));
        return solve(s1,s2,s3,0,0,0,dp);

        
    }
};

///////////////////////////BOTTOM UP //////////////////
class Solution {
public:
    int solve(string&s1 , string&s2,string&s3){
        vector<vector<vector<int>>>dp(s1.size()+1 , vector<vector<int>>(s2.size()+1 , vector<int>(s3.size()+1 , -1)));

        dp[s1.size()][s2.size()][s3.size()] = 1;

        for(int i = s1.size() ; i>=0 ;i--){
            for(int j = s2.size() ; j>=0 ; j--){
                for(int k = s3.size() ; k>=0 ; k--){
                    if(i == s1.size() && j == s2.size() && k == s3.size()) continue;


                    bool flag = false;

                    if(i< s1.size() && s1[i] == s3[k]){
                        flag = flag || dp[i+1][j][k+1];;
                    }

                    if( j < s2.size() && s2[j] == s3[k]){
                        flag = flag || dp[i][j+1][k+1];
                    }

                    dp[i][j][k] = flag;
                }
            }
        }
        return dp[0][0][0];



       
    }
    bool isInterleave(string s1, string s2, string s3) {

        
        return solve(s1,s2,s3);

        
    }
};





// Time Complexity: O(2^(m+n)), where m and n are the lengths of s1 and s2 respectively. This is because each character in s3 can be matched with either a character from s1 or s2, leading to an exponential number of recursive calls.
// Space Complexity: O(m + n) due to the recursion stack.



// Time Complexity: O(m * n * p), where m, n, and p are the lengths of s1, s2, and s3 respectively. This is because each state (i, j, k) is computed only once.
// Space Complexity: O(m * n * p) for the memoization table and O(m + n) for the recursion stack.




// Time Complexity: O(m * n * p), where m, n, and p are the lengths of s1, s2, and s3 respectively. This is because each state (i, j, k) is computed only once.
// Space Complexity: O(m * n * p) for the DP table.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), p = s3.size();
        if (m + n != p) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (i < m && s1[i] == s3[i + j]) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j];
                }
                if (j < n && s2[j] == s3[i + j]) {
                    dp[i][j] = dp[i][j] || dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution sol;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << (sol.isInterleave(s1, s2, s3) ? "True" : "False") << endl; // Output: True
    return 0;
}



// Time Complexity: O(m * n), where m is the length of s1 and n is the length of s2. This is because we iterate through each character in s1 and s2.
// Space Complexity: O(m * n). This is because we use a 2D DP table to store the results.
// isse jyada jaruri nahi hai kyunki 0ms time complexity