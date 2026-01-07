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
	Created: 08:25:45 PM(20:25:45) IST(+05:30) 07-01-2026 Wed
*/

class DSU {
public:
	DSU (int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int find_set(int a) {
		if (parent[a] == a) {
			return a;
		}
		return parent[a] = find_set(parent[a]);
	}

	bool union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (size[a] < size[b]) {
				swap(a, b);
			}
			parent[b] = a;
			size[a] += size[b];
			return true;
		}
		return false;
	}

private:
	vector<int> parent, size;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = (int)edges.size();
		DSU dsu(n);
		vector<int> ans;
		for (auto edge: edges) {
			int u = edge[0] - 1;
			int v = edge[1] - 1;
			if (!dsu.union_sets(u, v)) {
				ans = {u + 1, v + 1};
			}
		}
		return ans;
    }
};

void solve(){
	Solution s;
	vector<vector<int>> edges{{1,2},{1,3},{2,3}};
	auto ans = s.findRedundantConnection(edges);
	cout << "{" << ans[0] << ", " << ans[1] << "}\n";
	edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
	ans = s.findRedundantConnection(edges);
	cout << "{" << ans[0] << ", " << ans[1] << "}\n";
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
