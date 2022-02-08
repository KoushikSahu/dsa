#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
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
	Created: 07 February 2022 Mon 11:58:35
*/

struct Edge{
	int u, v, wt;
};

const int nxm = 1e5+5, INF = 1e9+5;
int n, m;
Edge e[nxm];

vint bellman_ford(int src){
	vint dist(n, INF);
	dist[src] = 0;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m; j++){
			Edge curr_edge = e[j];
			int u = curr_edge.u;
			int v = curr_edge.v;
			int wt = curr_edge.wt;
			if(dist[u] != INF){
				dist[v] = min(dist[v], dist[u] + wt);
			}
		}
	}
	return dist;
}

void solve(){
	cin>>n>>m;
	int u, v, wt;
	for(int i=0; i<m; i++){
		cin>>u>>v>>wt;
		e[i].u = u;
		e[i].v = v;
		e[i].wt = wt;
	}
	vint shortest_dist = bellman_ford(0);
	for(int i: shortest_dist) cout<<i<<' ';
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	// cin>>T; 
	while(T--){
		solve();
	}
	return 0;
}
