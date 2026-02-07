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
Created: 11:53:45 AM(11:53:45) IST(+05:30) 31-01-2026 Sat
 */

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
		int n = (int)matrix.size(), m = (int)matrix[0].size();

		vector<vector<int>> dp(n, vector<int>(m, -1));
		vector<vector<bool>> seen(n, vector<bool>(m, false));

		function<bool(int, int)> is_valid = [&](int x, int y) -> bool {
			return x >= 0 && x < n && y >= 0 && y < m;
		};

		function<int(int, int)> dfs = [&](int i, int j) -> int {
			seen[i][j] = true;

			vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

			int longest_length = 1;
			for (const auto& [dr, dc]: d) {
				int x = i + dr;
				int y = j + dc;

				if (is_valid(x, y) && !seen[x][y] && matrix[i][j] < matrix[x][y]) {
					if (dp[x][y] != -1) {
						longest_length = max(longest_length, dp[x][y] + 1);
					} else {
						longest_length = max(longest_length, 1 + dfs(x, y));
					}
				}
			}

			seen[i][j] = false;
			return dp[i][j] = longest_length;
		};

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] == -1) {
					ans = max(ans, dfs(i, j));
				} else {
					ans = max(ans, dp[i][j]);
				}
			}
		}
		
		return ans;
    }
};

void solve(){
	Solution s;

	vector<vector<int>> matrix {{ 9,9,4 },{ 6,6,8 },{ 2,1,1 }};
	cout << s.longestIncreasingPath(matrix) << '\n';

	matrix = {{ 3,4,5 },{ 3,2,6 },{ 2,2,1 }};
	cout << s.longestIncreasingPath(matrix) << '\n';

	matrix = {{1}};
	cout << s.longestIncreasingPath(matrix) << '\n';
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
