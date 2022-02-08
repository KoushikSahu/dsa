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
	Created: 08 February 2022 Tue 00:18:46
*/

const int nxm = 1e5+5, INF = 1e9+5;
int n, m;
vector<ipair> g[nxm];

vint bfs01(int src){
	vint dist(n, INF);
	deque<int> q;
	q.push_back(src);
	dist[src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		for(ipair p: g[u]){
			int v = p.first;
			int wt = p.second;
			if(dist[v] > dist[u] + wt){
				dist[v] = dist[u] + wt;
				if(wt==0) q.push_front(v);
				else q.push_back(v);
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
		g[u].push_back(make_pair(v, wt));
	}
	vint dist = bfs01(0);
	for(int i: dist) cout<<i<<' ';
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
