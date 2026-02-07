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
Created: 10:46:08 AM(10:46:08) IST(+05:30) 07-02-2026 Sat
 */

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		int n = (int)tickets.size();

		set<string> s;
		for (const vector<string>& ticket: tickets) {
			s.insert(ticket[0]);
			s.insert(ticket[1]);
		}
		int idx = -1;
		map<string, int> idxs;
		map<int, string> rev_mp;
		for (auto itr = s.begin(); itr != s.end(); itr++) {
			idx += 1;
			idxs[*itr] = idx;
			rev_mp[idx] = *itr;
		}

		vector<vector<int>> g(idxs.size());
		for (const vector<string>& ticket: tickets) {
			g[idxs[ticket[0]]].push_back(idxs[ticket[1]]);
		}
		for (vector<int>& v: g) {
			sort(v.begin(), v.end(), greater<int>());
		}

		n = idxs.size();
		vector<int> indegree(n, 0), outdegree(n, 0);
		for (int i = 0; i < n; i++) {
			outdegree[i] = g[i].size();
			for (int x: g[i]) {
				indegree[x] += 1;
			}
		}

		int v1 = -1, v2 = -1;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == outdegree[i]) continue;
			if (v1 == -1) {
				v1 = i;
			} else if (v2 == -1) {
				v2 = i;
			} else {
				return {};
			}
		}

		int src = idxs["JFK"];

		stack<int> st;
		st.push(src);
		vector<int> ans;
		while (!st.empty()) {
			int tp = st.top();
			st.pop();
			if (g[tp].size() == 0) {
				ans.push_back(tp);
				continue;
			}
			st.push(tp);
			st.push(g[tp].back());
			g[tp].pop_back();
		}

		vector<string> final_ans;
		for (int i: ans) {
			final_ans.push_back(rev_mp[i]);
		}

		reverse(final_ans.begin(), final_ans.end());
		return final_ans;
    }
};

void solve(){
	Solution s;

	vector<vector<string>> q {{ "MUC","LHR" },{ "JFK","MUC" },{ "SFO","SJC" },{ "LHR","SFO" }};
	debug(s.findItinerary(q));

	q = {{ "JFK","SFO" },{ "JFK","ATL" },{ "SFO","ATL" },{ "ATL","JFK" },{ "ATL","SFO" }};
	debug(s.findItinerary(q));

	q = {{"JFK", "ATL"}, {"ATL", "JFK"}};
	debug(s.findItinerary(q));
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
