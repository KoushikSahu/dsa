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
	Created: 09:53:07 PM(21:53:07) IST(+05:30) 09-12-2025 Tue
*/

/*
* dp[pos] = min no. of jumps required to reach pos from 0
* dp[pos] = min(dp[i], dp[i+1], ... dp[pos - 1]) where i...pos - 1 are the nodes from which pos is reachable + pos - i
*/

class Solution {
public:
    int jumpDp(vector<int>& nums) {
		int n = (int)nums.size();
		vector<int> dp(n, 0);
		for(int i=1; i<n; i++){
			int val = INT_MAX;
			for(int j=0; j<i; j++){
				if(j+nums[j] >= i){
					val = min(val, dp[j] + 1);
				}
			}
			dp[i] = val;
		}
		return dp[n-1];
    }

	int jump(vector<int>& nums) {
		int n = (int)nums.size();
		int ans = 0, curr_max = 0, curr_end = 0;
		for(int i=0; i<n-1; i++) {
			curr_max = max(curr_max, i + nums[i]);
			if(i == curr_end){
				ans += 1;
				curr_end = curr_max;
			}
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		vector a {2, 1};
		s.jump(a);
	}
	return 0;
}
