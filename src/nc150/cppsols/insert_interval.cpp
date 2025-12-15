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
	Created: 08:15:15 PM(20:15:15) IST(+05:30) 15-12-2025 Mon
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int low = 0, high = (int)intervals.size();
		while(low < high) {
			int mid = low + ((high - low) >> 1);
			if(intervals[mid][0] < newInterval[0]) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		intervals.insert(intervals.begin() + low, newInterval);
		vector<vector<int>> ans;
		vector<int> curr = intervals[0];
		for(int i=1; i < (int)intervals.size(); i++) {
			if(intervals[i][0] >= curr[0] && intervals[i][0] <= curr[1]) {
				curr[1] = max(curr[1], intervals[i][1]);
			} else {
				ans.push_back(curr);
				curr = intervals[i];
			}
		}
		if(ans.size() == 0 || ans.back() != curr) {
			ans.push_back(curr);
		}
		return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		// vvint a{{ 1,2 },{ 3,5 },{ 6,7 },{ 8,10 },{ 12,16 }};
		vvint a;
		vint b{4, 8};
		auto ans = s.insert(a, b);
		debug(ans);
	}
	return 0;
}
