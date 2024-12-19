class Solution {
public:
    string solveUsingRecursion(string a, string b, int i, int j) {
        // Base cases
        if (i >= a.length()) {
            // Add the remaining part of b
            return b.substr(j);
        }
        if (j >= b.length()) {
            // Add the remaining part of a
            return a.substr(i);
        }

        // Recursive calls
        if (a[i] == b[j]) {
            // If characters match, include it in the result
            return a[i] + solveUsingRecursion(a, b, i + 1, j + 1);
        } else {
            // If characters don't match, choose the shorter option and add the current character
            string option1 = a[i] + solveUsingRecursion(a, b, i + 1, j);
            string option2 = b[j] + solveUsingRecursion(a, b, i, j + 1);

            // Return the shorter of the two options
            return (option1.length() <= option2.length()) ? option1 : option2;
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return solveUsingRecursion(str1, str2, 0, 0) ;

        
        
    }
};



/// ////////////////////MEMO/
class Solution {
public:
    string solveUsingRecursion(string a, string b, int i, int j , vector<vector<string>> dp) {
        // Base cases
        if (i >= a.length()) {
            // Add the remaining part of b
            return b.substr(j);
        }
        if (j >= b.length()) {
            // Add the remaining part of a
            return a.substr(i);
        }

        if (!dp[i][j].empty()) {
            return dp[i][j];
        }

        // Recursive calls
        if (a[i] == b[j]) {
            // If characters match, include it in the result
            dp[i][j] =  a[i] + solveUsingRecursion(a, b, i + 1, j + 1 , dp);
        } else {
            // If characters don't match, choose the shorter option and add the current character
            string option1 = a[i] + solveUsingRecursion(a, b, i + 1, j ,dp );
            string option2 = b[j] + solveUsingRecursion(a, b, i, j + 1,dp);

            // Return the shorter of the two options
            dp[i][j] =  (option1.length() <= option2.length()) ? option1 : option2;
        }
        return dp[i][j];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<string>> dp(m, vector<string>(n, ""));

        return solveUsingRecursion(str1, str2, 0, 0 , dp ) ;

        
        
    }
};



