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
	Created: 11:28:04 PM(23:28:04) IST(+05:30) 26-12-2025 Fri
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) return false;
		bool dp[n1 + 1][n2 + 1];
		fill_n(&dp[0][0], (n1 + 1) * (n2 + 1), false);
		dp[0][0] = s3.length() == 0;
		for (int i = 1; i <= min(n1, n3); i++) {
			dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];
		}
		for (int i = 1; i <= min(n2, n3); i++) {
			dp[0][i] = (s2[i - 1] == s3[i - 1]) && dp[0][i - 1];
		}
		for (int i1 = 1; i1 <= n1; i1++) {
			for (int i2 = 1; i2 <= n2; i2++) {
				int i3 = i1 + i2;
				dp[i1][i2] |=
					(s3[i3 - 1] == s1[i1 - 1] ? dp[i1 - 1][i2] : false) ||
					(s3[i3 - 1] == s2[i2 - 1] ? dp[i1][i2 - 1] : false);
			}
		}
		return dp[n1][n2];
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << '\n';
		cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << '\n';
		cout << s.isInterleave("", "", "") << '\n';
	}
	return 0;
}
