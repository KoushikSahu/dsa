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
Created: 08:41:37 AM(08:41:37) IST(+05:30) 08-02-2026 Sun
 */

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int n = (int)position.size();
		vector<pair<long long, long long>> a;
		for (int i = 0; i < n; i++) {
			a.push_back({position[i], speed[i]});
		}
		sort(a.begin(), a.end(), [](const pair<long long, long long>& left, const pair<long, long>& right) -> bool {
			if (left.first != right.first) {
				return left.first > right.first;
			}
			return left.second < right.second;
		});
		int ans = 1;
		int mn = 0;
		for (int i = 1; i < n; i++) {
			if (1LL * (target - a[mn].first) * a[i].second < 1LL * (target - a[i].first) * a[mn].second) {
				ans += 1;
				mn = i;
			}
		}
		return ans;
    }
};

void solve(){
	Solution s;

	int target = 12;
	vector<int> position {10,8,0,5,3};
	vector<int> speed {2,4,1,1,3};
	cout << s.carFleet(target, position, speed) << '\n';

	target = 10;
	position = {6, 8};
	speed = {3, 2};
	cout << s.carFleet(target, position, speed) << '\n';
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
