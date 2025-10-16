#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define INF 1000000005
#define NEG_INF -1000000005
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/*
	Author: Koushik Sahu
	Created: 11:37:49 PM(23:37:49) IST(+05:30) 11-10-2025 Sat
*/

/*
* See * and the preceeding character as one?
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		vector<string> ptrns;
		for(int i = p.length()-1; i >= 0; i--) {
			if(p[i] == '*') {
				ptrns.push_back(p.substr(i-1, 2));
				i -= 1;
			} else {
				string str(1, p[i]);
				ptrns.push_back(str);
			}
		}
		reverse(ptrns.begin(), ptrns.end());

		bool dp[s.length() + 1][ptrns.size() + 1];
		fill_n(dp[0], (s.length() + 1)*(ptrns.size() + 1), false);

		dp[0][0] = true;
		for(int i=1; i<s.length(); i++) {
			dp[i][0] = false;
		}
		for(int i=1; i<ptrns.size(); i++) {
			dp[0][i] = ptrns[i-1].length() == 2 && dp[0][i-1];
		}

		/*
		* dp[i][j] = 
		* if ptrns[j] = char, if s[i] = char, dp[i][j] = dp[i-1][j-1], else false
		* if ptrns[j] = ., dp[i][j] = dp[i-1][j-1]
		* if ptrns[j] = char*, if s[i] = char, dp[i][j] = dp[i-1][j-1] || dp[i][j-1], else dp[i-1][j-1]
		* if ptrns[j] = .*, dp[i][j] = dp[i-1][j-1] || dp[i][j-1]
		*/
		for(int i=1; i<=s.length(); i++) {
			for(int j=1; j<=ptrns.size(); j++) {
				if(ptrns[j-1].length() == 1) {
					if(ptrns[j-1] == ".") {
						dp[i][j] = dp[i-1][j-1];
					} else {
						if(s[i-1] == ptrns[j-1][0]) {
							dp[i][j] = dp[i-1][j-1];
						} else {
							dp[i][j] = false;
						}
					}
				} else {
					if(ptrns[j-1][0] == '.') {
						dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
					} else {
						if(s[i-1] == ptrns[j-1][0]) {
							dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
						} else {
							dp[i][j] = dp[i][j-1];
						}
					}
				}
			}
		}
		return dp[s.length()][ptrns.size()];
	}

	bool isMatchRecursive(string s, string p) {
		vector<string> ptrns;
		for(int i = p.length()-1; i >= 0; i--) {
			if(p[i] == '*') {
				ptrns.push_back(p.substr(i-1, 2));
				i -= 1;
			} else {
				string str(1, p[i]);
				ptrns.push_back(str);
			}
		}
		reverse(ptrns.begin(), ptrns.end());
		vector<vector<int>> dp(s.length(), vector<int>(ptrns.size(), -1));
		return isMatchRecursive(s, 0, ptrns, 0, dp);
	}

	bool isMatchRecursive(string &s, int s_idx, vector<string> &ptrns, int p_idx, vector<vector<int>> &dp) {
		// debug(s, s_idx, ptrns, p_idx);
		if(s_idx >= s.length() && p_idx >= ptrns.size()) {
			return true;
		} else if (p_idx >= ptrns.size()) {
			return false;
		} else if (s_idx >= s.length()) {
			for(int i=p_idx; i < ptrns.size(); i++) {
				if(ptrns[i].length() < 2) return false;
			}
			return true;
		}
		if(dp[s_idx][p_idx] != -1) return dp[s_idx][p_idx];
		if(ptrns[p_idx].length() == 2) {
			if(ptrns[p_idx][0] == '.' || ptrns[p_idx][0] == s[s_idx]) {
				return dp[s_idx][p_idx] = isMatchRecursive(s, s_idx, ptrns, p_idx+1, dp) || isMatchRecursive(s, s_idx+1, ptrns, p_idx+1, dp) || isMatchRecursive(s, s_idx+1, ptrns, p_idx, dp);
			}
			return dp[s_idx][p_idx] = isMatchRecursive(s, s_idx, ptrns, p_idx+1, dp);
		}
		if(ptrns[p_idx][0] == '.' || ptrns[p_idx][0] == s[s_idx]) {
			return dp[s_idx][p_idx] = isMatchRecursive(s, s_idx+1, ptrns, p_idx+1, dp);
		}
		return dp[s_idx][p_idx] = false;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.isMatch("aa", "a") << '\n';
	cout << s.isMatch("aa", "a*") << '\n';
	cout << s.isMatch("ab", ".*") << '\n';
	cout << s.isMatch("a", "ab*") << '\n';
	cout << s.isMatch("ab", ".*c") << '\n';
	return 0;
}
