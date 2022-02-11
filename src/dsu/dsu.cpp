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
	Created: 08 February 2022 Tue 15:47:55
*/

class DSU {
	public:
		DSU(int n){
			dsu = new int[n];
			fill_n(dsu, n, -1);
		}

		int find(int x){
			if(dsu[x] < 0) return x;
			return dsu[x] = find(dsu[x]);
		}

		bool unionElements(int a, int b){
			int parenta = find(a);
			int parentb = find(b);
			if(parenta == parentb) return false;
			if(dsu[parentb] > dsu[parenta]){
				swap(a, b);
				swap(parenta, parentb);
			}
			dsu[parenta] += dsu[parentb];
			dsu[parentb] = parenta;
			return true;
		}

	private:
		int *dsu;
};

void solve(){
	DSU dsu(10);
	cout<<dsu.unionElements(1, 2)<<' ';
	cout<<dsu.unionElements(2, 3)<<' ';
	cout<<dsu.unionElements(3, 1)<<' ';
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
