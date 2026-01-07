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
	Created: 09:08:51 PM(21:08:51) IST(+05:30) 06-01-2026 Tue
*/

struct Comparator {
	bool operator()(const vector<int>& below, const vector<int>& above) {
		if (above[0] == below[0]) {
			return above[1] < below[1];
		}
		return above[0] < below[0];
	}
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
		int n = (int)points.size();

	   function<int(const vector<int>&, const vector<int>&)> manhattan = [](const vector<int>& p1, const vector<int>& p2) {
			return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
	   };

		vector<vector<int>> adj(n, vector<int>(n, 0));
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				adj[i][j] = adj[j][i] = manhattan(points[i], points[j]);
			}
		}

		priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;

		vector<int> seen(n, false);
		pq.push({0, 0});
		int ans = 0;
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();

			int wt = p[0];
			int v = p[1];

			if (!seen[v]) {
				seen[v] = true;

				ans += wt;

				for (int i = 0; i < n; i++) {
					if (!seen[i]) {
						pq.push({ adj[v][i], i });
					}
				}
			}
		}

		return ans;
    }
};

void solve(){
	Solution s;

	vector<vector<int>> pts {{0,0},{2,2},{3,10},{5,2},{7,0}};
	cout << s.minCostConnectPoints(pts) << '\n';

	pts = {{3,12},{-2,5},{-4,1}};
	cout << s.minCostConnectPoints(pts) << '\n';
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
