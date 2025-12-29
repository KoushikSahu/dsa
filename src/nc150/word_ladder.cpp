#include <bits/stdc++.h>
using namespace std;

/*
    Author: Koushik Sahu
    Created: 10:58:03 PM(22:58:03) IST(+05:30) 28-12-2025 Sun
    C++ version of Rust implementation
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int idx = n;

        // Find endWord in wordList
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                idx = i;
                break;
            }
        }

        if (idx == n) {
            return 0;
        }

        // Build adjacency list graph
        // Node 0 is beginWord, nodes 1 to n are wordList elements
        vector<vector<int>> g(n + 1);

        // Connect beginWord to words that differ by 1 character
        for (int i = 0; i < n; i++) {
            if (worddiffCnt(beginWord, wordList[i]) == 1) {
                g[0].push_back(i + 1);
                g[i + 1].push_back(0);
            }
        }

        // Connect words in wordList that differ by 1 character
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (worddiffCnt(wordList[i], wordList[j]) == 1) {
                    g[i + 1].push_back(j + 1);
                    g[j + 1].push_back(i + 1);
                }
            }
        }

        // BFS to find shortest path from node 0 to node idx+1
        queue<pair<int, int>> q; // {node_id, depth}
        vector<bool> seen(n + 1, false);

        q.push({0, 1});
        seen[0] = true;

        while (!q.empty()) {
            auto [nodeId, depth] = q.front();
            q.pop();

            if (nodeId == idx + 1) {
                return depth;
            }

            for (int neighbor : g[nodeId]) {
                if (!seen[neighbor]) {
                    seen[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }

        return 0;
    }

private:
    int worddiffCnt(const string& a, const string& b) {
        int n = a.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "tog", "cog"};

    int ans = sol.ladderLength(beginWord, endWord, wordList);
    cout << ans << endl;

    return 0;
}

