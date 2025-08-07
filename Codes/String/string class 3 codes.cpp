
#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
//this function normalises all the words and pattern into a similar format
//so that we can compare them and find the solution
    void createUpdateMapping(string& str) {
        //find mappping
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        //update the string
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans; 
        //firstly normalise the pattern
        createUpdateMapping(pattern);
        
        //saare words k sath khelna h 
        for(string s: words) {
            string tempString = s;         
            //normalise tempString
            createUpdateMapping(tempString);
            if(tempString == pattern) {
                //it means, that "s" wali string was a valid answer
                ans.push_back(s);
            }
        }
    return ans;
        
    }
};

// Time Complexity: O(n * m) n words with m length 
// Space Complexity: O(n)
// This approach maintains the same time and space complexity but uses a more concise and potentially more readable method to normalize the strings.


class Solution {
public:
    string normalize(const string& str) {
        unordered_map<char, char> mapping;
        char start = 'a';
        string normalized;

        for (char ch : str) {
            if (mapping.find(ch) == mapping.end()) {
                mapping[ch] = start++;
            }
            normalized += mapping[ch];
        }

        return normalized;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string normalizedPattern = normalize(pattern);

        for (const string& word : words) {
            if (normalize(word) == normalizedPattern) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};





























































//https://leetcode.com/problems/decode-the-message/

class Solution {
public:
    string decodeMessage(string key, string message) {
        //create mapping
        char start = 'a';
        char mapping[1000] = {0};

        for(auto ch: key) {
            if(ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }   
        //use mapping
        string ans;

        for(auto ch: message) {
            if(ch == ' ') {
                ans.push_back(' ');
            }
            else {
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }
    return ans;
    }
};


class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mapping;
        char start = 'a';

        for (char ch : key) {
            if (ch != ' ' && mapping.find(ch) == mapping.end()) {
                mapping[ch] = start++;
            }
        }

        string ans;
        for (char ch : message) {
            if (ch == ' ') {
                ans.push_back(' ');
            } else {
                ans.push_back(mapping[ch]);
            }
        }

        return ans;
    }
};

// Time Complexity:
// The first loop iterates through each character in the key string to create the mapping. This has a time complexity of O(k), where k is the length of the key.
// The second loop iterates through each character in the message string to decode it. This has a time complexity of O(m), where m is the length of the message.
// Therefore, the overall time complexity is O(k + m).

// Space Complexity:
// The space complexity is O(1) for the mapping array, as it has a fixed size of 1000.
// The space complexity for the ans string is O(m), where m is the length of the message.
















































































//https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0;
        int pickM = 0;
        int pickG = 0;

        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        int lastP = 0;
        int lastG = 0;
        int lastM = 0;

        //calculate pick time and travel time
        for(int i=0; i<garbage.size(); i++) {
            string curr = garbage[i];
            
            for(int j=0; j<curr.length(); j++) {
                char ch = curr[j];

                if(ch =='P') {
                    pickP++;
                    lastP = i;
                }
                else if(ch =='G') {
                    pickG++;
                    lastG = i;
                }
                else if(ch == 'M' ) {
                    pickM++;
                    lastM = i;
                }

            }
            
        }

        //calculate travel time
        for(int i=0; i<lastP; i++) {
            travelP += travel[i];
        }

        for(int i=0; i<lastG; i++) {
            travelG += travel[i];
        }

         for(int i=0; i<lastM; i++) {
            travelM += travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        return ans;
    }
};

// Summary:
// Time Complexity: O(n * m)
// Space Complexity: O(1)
// This approach maintains the same time and space complexity but makes the code more concise and potentially more readable by combining the loops and reducing redundant calculations.

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0, pickM = 0, pickG = 0;
        int travelP = 0, travelG = 0, travelM = 0;
        int lastP = -1, lastG = -1, lastM = -1;

        // Calculate pick time and last positions
        for (int i = 0; i < garbage.size(); i++) {
            for (char ch : garbage[i]) {
                if (ch == 'P') {
                    pickP++;
                    lastP = i;
                } else if (ch == 'G') {
                    pickG++;
                    lastG = i;
                } else if (ch == 'M') {
                    pickM++;
                    lastM = i;
                }
            }
        }

        // Calculate travel time
        for (int i = 1; i < garbage.size(); i++) {
            if (i <= lastP) travelP += travel[i - 1];
            if (i <= lastG) travelG += travel[i - 1];
            if (i <= lastM) travelM += travel[i - 1];
        }

        return pickP + travelP + pickG + travelG + pickM + travelM;
    }
};





























































//https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    //custom comparator
    static string str;
    static bool compare(char char1, char char2) {
        
        //this will return true, if position of character1 in str string is
        //less than the position of character2 in str string

        //when true is returned, then char1 will be placed before char2 in 
        //output string
        return (str.find(char1) < str.find(char2));

    }
    string customSortString(string order, string s) {
        
        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
//string Solution::str;



// Time and Space Complexity
// Time Complexity:
// The find function inside the compare function has a time complexity of O(m), where m is the length of the order string.
// The sort function has a time complexity of O(n log n), where n is the length of the string s. Since the compare function is called for each comparison, the overall time complexity becomes O(n log n * m).
// Space Complexity:
// The space complexity is O(1) for the extra space used, as we are not using any additional data structures that grow with the input size.
// Optimization
// We can optimize the customSortString function by using a more efficient approach. Instead of using the find function inside the comparator, we can create a mapping of characters to their positions in the order string. This reduces the time complexity of each comparison to O(1).

// Here is the optimized version:


class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> charOrder;
        for (int i = 0; i < order.size(); ++i) {
            charOrder[order[i]] = i;
        }

        sort(s.begin(), s.end(), [&charOrder](char a, char b) {
            return charOrder[a] < charOrder[b];
        });

        return s;
    }
};

// Explanation:
// Create an unordered_map to store the position of each character in the order string.
// Use the sort function with a custom comparator that uses the unordered_map to compare the positions of characters.
// The custom comparator now has a time complexity of O(1) for each comparison.
// Summary:
// Time Complexity: O(n log n), where n is the length of the string s.
// Space Complexity: O(m), where m is the length of the order string, due to the unordered_map.
// This approach is more efficient as it reduces the time complexity of each comparison from O(m) to O(1), resulting in an overall time complexity of O(n log n).