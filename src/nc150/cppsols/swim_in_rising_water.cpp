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
	Created: 09:38:08 PM(21:38:08) IST(+05:30) 19-01-2026 Mon
*/

class Solution {
public:
    int swimInWaterBruteForce(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int ans = INT_MAX;
		vector<vector<bool>> seen(n, vector<bool>(m, false));

		function<void(int, int, int, int&)> dfs;
		dfs = [this, &grid, &seen, &dfs](int x, int y, int curr, int& ans) -> void {
			seen[x][y] = true;
			curr = max(curr, grid[x][y]);

			if (curr > ans) {
				return;
			}

			if (x == grid.size() - 1 && y == grid[0].size() - 1) {
				ans = min(ans, curr);
			}

			int dr[] = {-1, 1, 0, 0};
			int dc[] = {0, 0, -1, 1};

			for (int i = 0; i < 4; i++) {
				int r = x + dr[i];
				int c = y + dc[i];

				if (is_valid(r, c, grid.size(), grid[0].size()) && !seen[r][c]) {
					dfs(r, c, curr, ans);
				}
			}

			seen[x][y] = false;
		};

		dfs(0, 0, INT_MIN, ans);

		return ans;
    }

    int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();

		function<bool(int, int, vector<vector<bool>>&, int)> dfs = [this, &dfs, &grid, n, m](int x, int y, vector<vector<bool>>& seen, int mx_lvl) -> bool {
			seen[x][y] = true;
			if (grid[x][y] > mx_lvl) return false;
			if (x == n - 1 && y == m - 1) return true;

			vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
			bool ans = false;
			for (auto [dr, dc]: directions) {
				int r = x + dr;
				int c = y + dc;
				if (is_valid(r, c, n, m) && !seen[r][c]) {
					ans |= dfs(r, c, seen, mx_lvl);
				}
			}

			return ans;
		};

		int low = 0, high = n * m;
		vector<vector<bool>> seen(n, vector<bool>(m, false));
		while (low < high) {
			int mid = low + (high - low) / 2;
			for_each(seen.begin(), seen.end(), [](vector<bool>& row) {
				fill(row.begin(), row.end(), false);
			});
			if (!dfs(0, 0, seen, mid)) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return low;
    }

private:
	bool is_valid(int x, int y, int n, int m) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}
};

void solve() {
	Solution s;

	vector<vector<int>> a {{ 0,2 },{ 1,3 }};
	cout << s.swimInWater(a) << '\n';

	a = {{ 0,1,2,3,4 },{ 24,23,22,21,5 },{ 12,13,14,15,16 },{ 11,17,18,19,20 },{ 10,9,8,7,6 }};
	cout << s.swimInWater(a) << '\n';

	int nxm = 50;
	vector<vector<int>> scale_test(nxm, vector<int>(nxm));
	for (int i = 0; i < nxm; i++) {
		for (int j = 0; j < nxm; j++) {
			scale_test[i][j] = rand() % (nxm * nxm - 0 + 1) + nxm * nxm;
		}
	}
	cout << s.swimInWater(scale_test) << '\n';
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
