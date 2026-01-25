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
	Created: 12:38:36 PM(12:38:36) IST(+05:30) 25-01-2026 Sun
*/

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<int> dist(n, inf);
		dist[src] = 0;
		for (int i = 0; i < k + 1; i++) {
			vector<int> tmp = dist;
			for (const auto& flight: flights) {
				int u = flight[0], v = flight[1], wt = flight[2];
				if (dist[u] + wt < tmp[v]) {
					tmp[v] = dist[u] + wt;
				}
			}
			dist = tmp;
		}
		return dist[dst] < inf ? dist[dst] : -1;
	}

	int findCheapestPriceMatmul(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<int>> g(n, vector<int>(n, inf));
		for (const auto& flight: flights) {
			int u = flight[0], v = flight[1], wt = flight[2];
			g[u][v] = wt;
		}
		vector<vector<int>> ans = g;
		int fin_ans = ans[src][dst];
		for (int i = 0; i < k; i++) {
			ans = matmul(ans, g);
			fin_ans = min(ans[src][dst], fin_ans);
		}
		return fin_ans == inf ? -1 : fin_ans;
	}

private:
	const int inf = 1e9 + 7;

	vector<vector<int>> matmul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
		int n = a.size();
		vector<vector<int>> c(n, vector<int>(n, inf));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
				}
			}
		}
		return c;
	}

	// vector<vector<int>> binexpo(vector<vector<int>> a, int k) {
	// 	vector<vector<int>> ans = a;
	// 	while (k) {
	// 		if (k % 2) {
	// 			ans = matmul(ans, a);
	// 		}
	// 		a = matmul(a, a);
	// 		k /= 2;
	// 	}
	// 	return ans;
	// }
};

void solve(){
	Solution s;

	int n = 3;
	vector<vector<int>> flights {{ 0,1,100 },{ 1,2,100 },{ 0,2,500 }};
	int src = 0;
	int dst = 2;
	int k = 0;
	int ans = s.findCheapestPrice(n, flights, src, dst, k);

	cout << ans << '\n';
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
