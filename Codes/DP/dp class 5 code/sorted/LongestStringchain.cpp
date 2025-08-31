#include<bits/stdc++.h>
using namespace std;

bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}


int longestStrChain(vector<string>& arr){

    int n = arr.size();
    
    //sort the array
    
    sort(arr.begin(), arr.end(),comp);

    vector<int> dp(n,1);
    
    int maxi = 1;
    
    for(int i=0; i<=n-1; i++){
        
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if( compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
            }
        }
        
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}
    

int main() {
	
	vector<string> words = {"a","b","ba","bca","bda","bdca"};
	
	cout<<" The length of the longest string chain is : "<<longestStrChain(words);
	
}



// above approach is good but below is more good approach 

#include <bits/stdc++.h>
using namespace std;

int longestStrChain(vector<string>& words) {
    // Sort words by their lengths
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });

    unordered_map<string, int> dp; // dp[word] stores the longest chain ending at 'word'
    int maxi = 1;

    for (string word : words) {
        dp[word] = 1; // Minimum chain length for a single word is 1
        for (int i = 0; i < word.size(); i++) {
            // Remove one character from the word
            string prev = word.substr(0, i) + word.substr(i + 1);
            if (dp.find(prev) != dp.end()) {
                dp[word] = max(dp[word], dp[prev] + 1);
            }
        }
        maxi = max(maxi, dp[word]); // Update global maximum chain length
    }

    return maxi;
}

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << "The length of the longest string chain is: " << longestStrChain(words) << endl;
}
