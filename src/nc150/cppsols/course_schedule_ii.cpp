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
	Created: 08:31:21 PM(20:31:21) IST(+05:30) 11-01-2026 Sun
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
 		vector<vector<int>> g(numCourses);
		vector<int> indegree(numCourses);
		for (const auto& prerequisite: prerequisites) {
			g[prerequisite[1]].push_back(prerequisite[0]);
			indegree[prerequisite[0]] += 1;
		}
		queue<int> q;
		vector<int> topo;
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int tp = q.front();
			q.pop();
			topo.push_back(tp);
			for (int v: g[tp]) {
				indegree[v] -= 1;
				if (indegree[v] == 0) {
					q.push(v);
				}
			}
		}
		return topo.size() == numCourses ? topo : vector<int>();
    }
};

void solve(){
	Solution s;

	int numCourses = 2;
	vector<vector<int>> prerequisites {{ 1,0 }};
	debug(s.findOrder(numCourses, prerequisites));

	prerequisites = { { 1,0 },{ 0,1 } };
	debug(s.findOrder(numCourses, prerequisites));

	numCourses = 4;
	prerequisites = {{ 1,0 },{ 2,0 },{ 3,1 },{ 3,2 }};
	debug(s.findOrder(numCourses, prerequisites));
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
