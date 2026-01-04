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
	Created: 12:18:23 PM(12:18:23) IST(+05:30) 04-01-2026 Sun
*/

class Solution {
public:
    bool checkValidString(string s) {
		vector<vector<int>> dp(s.length() + 1, vector<int>(2 * (s.length() + 1), -1));
		return checkValidString(s, 0, 0, dp);
    }

private:
	bool checkValidString(const string& s, const int& pos, int balance, vector<vector<int>>& dp) {
		if (balance < 0) {
			return dp[pos][balance + s.length()] = false;
		}
		if (s.length() == pos) {
			return dp[pos][balance + s.length()] = balance == 0;
		}
		if (dp[pos][balance + s.length()] != -1) {
			return dp[pos][balance + s.length()];
		}
		switch (s[pos]) {
			case '(':
				return dp[pos][balance + s.length()] = checkValidString(s, pos + 1, balance + 1, dp);
			case ')':
				return dp[pos][balance + s.length()] = checkValidString(s, pos + 1, balance - 1, dp);
			default:
				return dp[pos][balance + s.length()] = checkValidString(s, pos + 1, balance + 1, dp) ||
							checkValidString(s, pos + 1, balance, dp) ||
							checkValidString(s, pos + 1, balance - 1, dp);
		}
	}
};

void solve(){
	Solution s;
	cout << s.checkValidString("()") << '\n';
	cout << s.checkValidString("(*)") << '\n';
	cout << s.checkValidString("(*))") << '\n';
	cout << s.checkValidString("(") << '\n';
	cout << s.checkValidString("((") << '\n';
	cout << s.checkValidString("(()") << '\n';
	cout << s.checkValidString("((**") << '\n';
	cout << s.checkValidString("(()*") << '\n';
	string stress_test(100, '*');
	cout << s.checkValidString(stress_test) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
