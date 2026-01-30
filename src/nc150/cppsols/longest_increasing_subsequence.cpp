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
Created: 08:15:11 PM(20:15:11) IST(+05:30) 27-01-2026 Tue
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = (int)nums.size();
		vector<int> a{nums[0]};
		a.reserve(n);
		for (int i = 1; i < n; i++) {
			int low = 0;
			int high = a.size();
			while (low < high) {
				int mid = low + (high - low) / 2;
				if (a[mid] < nums[i]) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			if (low == a.size()) {
				a.push_back(nums[i]);
			} else {
				a[low] = nums[i];
			}
		}
		return a.size();
    }

    int lengthOfLISDp(vector<int>& nums) {
		int n = (int)nums.size();
		vector<int> dp(n, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
    }
};

void solve(){
	Solution s;

	vector<int> nums{10,9,2,5,3,7,101,18};
	cout << s.lengthOfLIS(nums) << '\n';

	nums = {0,1,0,3,2,3};
	cout << s.lengthOfLIS(nums) << '\n';

	nums = {7,7,7,7,7,7,7};
	cout << s.lengthOfLIS(nums) << '\n';
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
