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
Created: 10:38:28 AM(10:38:28) IST(+05:30) 31-01-2026 Sat
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
		int n = (int)nums.size();
		int dp[n][n];
		fill_n(dp[0], n*n, 0);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (i == j) {
					dp[i][j] = nums[i] * (i - 1 >= 0 ? nums[i - 1] : 1) * (i + 1 < n ? nums[i + 1] : 1);
					continue;
				}
				for (int k = i; k <= j; k++) {
					dp[i][j] = max(dp[i][j], (k - 1 >= 0 ? dp[i][k - 1] : 0) + (k + 1 < n ? dp[k + 1][j] : 0) + (i - 1 >= 0 ? nums[i - 1] : 1) * nums[k] * (j + 1 < n ? nums[j + 1] : 1));
				}
			}
		}
		return dp[0][n-1];
    }
};

void solve(){
	Solution s;

	vector<int> nums {3, 1, 5, 8};
	cout << s.maxCoins(nums) << '\n';

	nums = {1, 5};
	cout << s.maxCoins(nums) << '\n';
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
