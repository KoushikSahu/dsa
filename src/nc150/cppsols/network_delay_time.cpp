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
	Created: 04:04:27 PM(16:04:27) IST(+05:30) 15-01-2026 Thu
*/

struct Comparator {
	bool operator()(const pair<int, int>& below, const pair<int, int>& above) {
		return above.second < below.second;
	}
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int>>> g(n);

		for (const auto& time: times) {
			int u = time[0] - 1;
			int v = time[1] - 1;
			int wt = time[2];

			g[u].push_back({v, wt});
		}

		k = k - 1;

		priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> q;
		q.push({k, 0});
		int dist[n];
		fill_n(dist, n, INT_MAX);
		dist[k] = 0;

		while (!q.empty()) {
			auto p = q.top();
			q.pop();

			int u = p.first;
			int curr_wt = p.second;

			if (curr_wt > dist[u]) {
				continue;
			}

			for (const auto& pp: g[u]) {
				int v = pp.first;
				int wt = pp.second;

				if (dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
					q.push({v, dist[v]});
				}
			}
		}

		if (all_of(dist, dist + n, [](int x) { return x < INT_MAX; })) {
			return *max_element(dist, dist + n);
		}
		
		return -1;
    }
};

void solve(){
	Solution s;

	vector<vector<int>> times = {{ 2,1,1 },{ 2,3,1 },{ 3,4,1 }};
	int n = 4;
	int k = 2;
	cout << s.networkDelayTime(times, n, k) << '\n';

	times = {{1,2,1}};
	n = 2;
	k = 1;
	cout << s.networkDelayTime(times, n, k) << '\n';

	times = {{1,2,1}};
	n = 2;
	k = 2;
	cout << s.networkDelayTime(times, n, k) << '\n';

	times = {{ 1,2,1 }, { 2,3,2 }, { 1,3,2 }};
	n = 3;
	k = 1;
	cout << s.networkDelayTime(times, n, k) << '\n';
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
