#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string&str){
        int count = 0 ;
        for(char ch : str){
            if(ch == '1'){
                count++;

            }
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        int n  = bank.size();
        vector<int>num(n);
        int i = 0 ;
        for(string str : bank){
            int count = solve(str);
            if(count != 0){
                num[i] = count;
                i++;
            }  
        }

        int ans  = 0;
        for(int i = 0 ; i < num.size()-1 ; i++){
            ans  += num[i]*num[i+1];
        }
        return ans;
    }
};

// upper  is my solution and has O(n*m) time complexity and O(n) space complexity
//  below has O(n.m) time complexity and O(1) space complexity

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int prevDevices = 0, beams = 0;
        for (const string &row : bank)
        {
            int currentDevices = count(row.begin(), row.end(), '1'); // Count '1's in the current row
            if (currentDevices > 0)
            {
                beams += prevDevices * currentDevices;
                prevDevices = currentDevices;
            }
        }
        return beams;
    }
};




// import java.util.*;

// public class Solution {
//     public int numberOfBeams(String[] bank) {
//         int prevDevices = 0;
//         int beams = 0;

//         for (String row : bank) {
//             int currentDevices = 0;

//             // Count the number of '1's in the row
//             for (char c : row.toCharArray()) {
//                 if (c == '1') {
//                     currentDevices++;
//                 }
//             }

//             if (currentDevices > 0) {
//                 beams += prevDevices * currentDevices;
//                 prevDevices = currentDevices;
//             }
//         }

//         return beams;
//     }

//     // Optional main to test
//     public static void main(String[] args) {
//         Solution sol = new Solution();
//         String[] bank = {"011001", "000000", "010100", "001000"};
//         System.out.println(sol.numberOfBeams(bank));  // Output: 8
//     }
// }
