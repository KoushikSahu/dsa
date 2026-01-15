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
	Created: 08:59:17 PM(20:59:17) IST(+05:30) 13-01-2026 Tue
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = (int)nums.size();
		switch (n) {
			case 1: return nums[0];
			case 2: return max(nums[0], nums[1]);
			default: return max(max_stolen(nums, 0, n - 2), max_stolen(nums, 1, n - 1)); 
		}
	}

private:
	int max_stolen(const vector<int>& nums, int start, int end) {
		int n = end - start + 1;
		vector<int> dp(n, 0);
		dp[0] = nums[start];
		dp[1] = max(nums[start], nums[start + 1]);
		for (int i = start + 2; i <= end; i++) {
			int idx = i - start;
			dp[idx] = max(nums[i] + dp[idx - 2], dp[idx - 1]);
		}
		return dp[n - 1];
	}
};

void solve(){
	Solution s;

	vector<int> a{2, 3, 2};
	cout << s.rob(a) << '\n';

	a = {1, 2, 3, 1};
	cout << s.rob(a) << '\n';

	a = {1, 2, 3};
	cout << s.rob(a) << '\n';

	a = {1, 3, 1, 3, 100};
	cout << s.rob(a) << '\n';
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
