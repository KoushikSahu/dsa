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
	Created: 08:41:03 PM(20:41:03) IST(+05:30) 06-01-2026 Tue
*/

class Solution {
public:
    vector<int> twoSumBinarySearch(vector<int>& numbers, int target) {
		int n = (int)numbers.size();
		for (int i = 0; i < n - 1; i++) {
			int a = numbers[i];
			int low = i + 1, high = n;
			while (low < high) {
				int mid = low + (high - low) / 2;
				if (numbers[mid] < (target - a)) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			if (low == n) {
				continue;
			}
			if (numbers[low] == target - a) {
				return {i + 1, low + 1};
			}
		}
		return {-1, -1};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
		int n = (int)numbers.size();
		int low = 0, high = n - 1;
		while (low < high) {
			int sm = numbers[low] + numbers[high];
			if (sm == target) {
				return {low + 1, high + 1};
			} else if (sm < target) {
				low += 1;
			} else {
				high -= 1;
			}
		}
		return {-1, -1};
    }
};

void solve(){
	Solution s;
	vector<int> a {2, 7, 11, 15};
	debug(s.twoSum(a, 9));
	a = {2, 3, 4};
	debug(s.twoSum(a, 6));
	a = {-1, 0};
	debug(s.twoSum(a, -1));
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
