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
	Created: 11:41:04 PM(23:41:04) IST(+05:30) 24-12-2025 Wed
*/

class Solution {
public:
    string minWindow(string s, string t) {
		array<int, 128> mps, mpt;
		mps.fill(0);
		mpt.fill(0);
		for (char c: t) {
			mpt[c - 'A'] += 1;
		}
		int ssz = s.length(), low = 0, high = -1;
		int ans_low = -1, ans_high = -1;
		while (low < ssz) {
			while (high + 1 < ssz && !is_satisfied(mps, mpt)) {
				high += 1;
				mps[s[high] - 'A'] += 1;
			}
			if (is_satisfied(mps, mpt)) {
				if (ans_low == -1 || high - low + 1 < ans_high - ans_low + 1) {
					ans_high = high;
					ans_low = low;
				}
			}
			mps[s[low] - 'A'] -= 1;
			low += 1;
		}
		return ans_low == -1 ? "" : s.substr(ans_low, ans_high - ans_low + 1);
    }

private:
	bool is_satisfied(array<int, 128>& mps, array<int, 128>& mpt) {
		for (int i = 0; i < 128; i++) {
			if (mps[i] < mpt[i]) return false;
		}
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		cout << s.minWindow("ADOBECODEBANC", "ABC") << '\n';
		cout << s.minWindow("a", "a") << '\n';
		cout << s.minWindow("a", "aa") << '\n';
	}
	return 0;
}
