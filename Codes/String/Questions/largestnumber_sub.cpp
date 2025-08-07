#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool mycomp(string a , string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto n : nums){
            snums.push_back(to_string(n));
        }

        sort(snums.begin() , snums.end() , mycomp);
        if(snums[0] == "0")return "0";
        string ans = "";
        for(auto str:snums){
            ans+=str;

        }
        return ans;
        
    }
};





// class Solution {
//     public String largestNumber(int[] nums) {
       
//         String[] snums = new String[nums.length];
//         for (int i = 0; i < nums.length; i++) {
//             snums[i] = String.valueOf(nums[i]);
//         }
//         Arrays.sort(snums, (a, b) -> (b + a).compareTo(a + b));
//         if (snums[0].equals("0")) return "0";

//         StringBuilder ans = new StringBuilder();
//         for (String str : snums) {
//             ans.append(str);
//         }

//         return ans.toString();
//     }
// }


// Time and Space Complexity
// Time Complexity:
// Conversion to Strings:

// Converting each integer in nums to a string takes O(n) time, where n is the number of elements in nums.
// Sorting:

// The sorting step uses a custom comparator and sorts the snums vector. The time complexity of sorting is O(n log n), where n is the number of elements in snums.
// Concatenation:

// Concatenating the sorted strings to form the final result takes O(n * m) time, where m is the average length of the strings.
// Overall, the time complexity is O(n log n + n * m).

// Space Complexity:
// The space complexity is O(n) for storing the snums vector, which contains the string representations of the integers.
// Optimized Approach
// The current implementation is already quite efficient. However, we can make the code more concise and readable. The time complexity of the sorting step is the dominant factor, and it cannot be improved beyond O(n log n) for comparison-based sorting algorithms.

// Here is the optimized version:
// the code is same as the last one we wrote but the code is more concise and readable

// Conversion to Strings: Convert each integer in nums to a string and store it in the snums vector.
// Sorting: Sort the snums vector using a custom comparator that compares the concatenated results of two strings.
// Check for Leading Zero: If the largest number is "0", return "0" to handle the case where all numbers are zero.
// Concatenation: Concatenate the sorted strings to form the final result.
// Summary:
// Time Complexity: O(n log n + n * m), where n is the number of elements in nums and m is the average length of the strings.
// Space Complexity: O(n) for storing the snums vector.
// This approach is already optimal for the problem, and the code is concise and readable.

