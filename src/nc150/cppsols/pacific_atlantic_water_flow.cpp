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
Created: 10:32:36 AM(10:32:36) IST(+05:30) 08-02-2026 Sun
 */

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		int n = (int)heights.size(), m = (int)heights[0].size();
		vector<vector<bool>> pacific(n, vector<bool>(m, false));
		vector<vector<bool>> atlantic(n, vector<bool>(m, false));
		
		auto is_valid = [&](int x, int y) -> bool {
			return x >= 0 && x < n && y >= 0 && y < m;
		};
		
		function<void(int, int, vector<vector<bool>>&)> dfs = [&](int x, int y, vector<vector<bool>>& visited) {
			visited[x][y] = true;
			vector<pair<int, int>> dirs {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
			for (auto [dr, dc]: dirs) {
				int r = x + dr;
				int c = y + dc;
				if (is_valid(r, c) && !visited[r][c] && heights[r][c] >= heights[x][y]) {
					dfs(r, c, visited);
				}
			}
		};
		
		for (int i = 0; i < n; i++) {
			dfs(i, 0, pacific);
		}
		for (int j = 0; j < m; j++) {
			dfs(0, j, pacific);
		}
		for (int i = 0; i < n; i++) {
			dfs(i, m - 1, atlantic);
		}
		for (int j = 0; j < m; j++) {
			dfs(n - 1, j, atlantic);
		}
		
		vector<vector<int>> ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pacific[i][j] && atlantic[i][j]) {
					ans.push_back({i, j});
				}
			}
		}
		return ans;
    }
};

void solve(){
	Solution s;

	vector<vector<int>> heights {{ 1,2,2,3,5 },{ 3,2,3,4,4 },{ 2,4,5,3,1 },{ 6,7,1,4,5 },{ 5,1,1,2,4 }};
	debug(s.pacificAtlantic(heights));
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
