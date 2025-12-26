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
	Created: 06:06:10 PM(18:06:10) IST(+05:30) 25-12-2025 Thu
*/

class Solution {
public:
    int numDecodingsRecursive(string s) {
		vector<int> dp(s.length(), -1);
		return recurse(s, 0, dp);
    }

    int numDecodings(string s) {
		vector<int> dp(s.length(), 0);
		dp[0] = s[0] - '0' != 0 ? 1 : 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] - '0' != 0) {
				dp[i] += dp[i-1];
			}
			if (s[i-1] != '0') {
				int num = (s[i-1] - '0') * 10 + (s[i] - '0');
				if (num <= 26) {
					dp[i] += (i - 2 < 0 ? 1 : dp[i-2]);
				}
			}
		}
		return dp[s.length() - 1];
    }

private:
	int recurse(string s, int idx, vector<int>& dp) {
		if (idx == s.length()) return 1;
		if (s[idx] == '0') return 0;
		if (dp[idx] != -1) return dp[idx];
		int ans = recurse(s, idx + 1, dp);
		if (idx + 1 < s.length()) {
			int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
			if (num <= 26) {
				ans += recurse(s, idx + 2, dp);
			}
		}
		return dp[idx] = ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		cout << s.numDecodings("12") << '\n';
		cout << s.numDecodings("226") << '\n';
		cout << s.numDecodings("06") << '\n';
		cout << s.numDecodings("27") << '\n';
	}
	return 0;
}
