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
Created: 05:12:26 PM(17:12:26) IST(+05:30) 07-02-2026 Sat
 */

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
		if (hand.size() % groupSize != 0) return false;
		map<int, int> frq;
		for (int i: hand) {
			frq[i] += 1;
		}
		bool ans = true;
		while (!frq.empty()) {
			bool continuous = true;
			int k = 0;
			vector<int> grp;
			for (auto itr = frq.begin(); itr != frq.end() && k < groupSize; itr++, k++) {
				grp.push_back(itr->first);
				itr->second -= 1;
			}
			if (grp.size() != groupSize) {
				return false;
			}
			for (int i = 1; i < grp.size(); i++) {
				continuous &= (grp[i] - grp[i - 1] == 1);
			}
			vector<int> to_remove;
			for (auto itr = frq.begin(); itr != frq.end(); itr++) {
				if (itr->second == 0) {
					to_remove.push_back(itr->first);
				}
			}
			for (int i: to_remove) {
				frq.erase(i);
			}
			ans &= continuous;
		}
		return ans;
    }
};

void solve(){
	Solution s;

	vector<int> hand {1,2,3,6,2,3,4,7,8};
	int groupSize = 3;
	cout << s.isNStraightHand(hand, groupSize) << '\n';

	hand = {1, 2, 3, 4, 5};
	groupSize = 4;
	cout << s.isNStraightHand(hand, groupSize) << '\n';

	hand = {1, 1, 2, 2, 3, 3};
	groupSize = 2;
	cout << s.isNStraightHand(hand, groupSize) << '\n';
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
