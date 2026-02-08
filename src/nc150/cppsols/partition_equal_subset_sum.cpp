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
Created: 10:19:09 AM(10:19:09) IST(+05:30) 08-02-2026 Sun
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int n = (int)nums.size();
		int sm = 0;
		for (int i = 0; i < n; i++) sm += nums[i];
		if (sm % 2 == 1) return false;
		int hlf = sm / 2;
		bool dp[200][hlf + 1];
		fill_n(dp[0], 200 * (hlf + 1), false);
		if (nums[0] <= hlf) dp[0][nums[0]] = true;
		dp[0][0] = true;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= hlf; j++) {
				dp[i][j] = (j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] : false) || dp[i - 1][j];
			}
		}
		bool ans = false;
		for (int i = 0; i < n; i++) ans |= dp[i][hlf];
		return ans;
    }
};

void solve(){
	Solution s;

	vector<int> nums {1, 5, 11, 5};
	cout << s.canPartition(nums) << '\n';

	nums = {1, 2, 3, 5};
	cout << s.canPartition(nums) << '\n';
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
