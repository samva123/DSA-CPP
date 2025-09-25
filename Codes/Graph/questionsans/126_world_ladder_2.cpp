#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (!dict.count(endWord)) return result;

        unordered_map<string, vector<string>> parents; // adjacency: who leads to whom
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);

        bool found = false;
        while (!currentLevel.empty() && !found) {
            for (auto &w : currentLevel) dict.erase(w); // remove visited
            for (auto &w : currentLevel) {
                string word = w;
                for (int i = 0; i < word.size(); i++) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (!dict.count(word)) continue;
                        nextLevel.insert(word);
                        parents[word].push_back(w);
                        if (word == endWord) found = true;
                    }
                    word[i] = orig;
                }
            }
            swap(currentLevel, nextLevel);
            nextLevel.clear();
        }

        if (found) {
            vector<string> path = {endWord};
            backtrack(endWord, beginWord, parents, path, result);
        }
        return result;
    }

    void backtrack(string word, string &beginWord,
                   unordered_map<string, vector<string>> &parents,
                   vector<string> &path, vector<vector<string>> &result) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }
        for (auto &p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
