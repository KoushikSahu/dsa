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
	Created: 10:33:57 PM(22:33:57) IST(+05:30) 18-10-2025 Sat
*/

class Solution{
public:
	vector<string> recurse(string& digits, int idx, map<int, vector<char>>& mp) {
		if(idx == digits.size()){
			return {""};
		}
		auto strs = recurse(digits, idx+1, mp);
		vector<string> ans;
		auto digit = digits[idx] - '0';
		for(auto i: strs){
			for(auto j: mp[digit]){
				ans.push_back(j + i);
			}
		}
		return ans;
	}

	vector<string> letterCombinations(string digits){
		map<int, vector<char>> mp = {
			{2, {'a', 'b', 'c'}},
			{3, {'d', 'e', 'f'}},
			{4, {'g', 'h', 'i'}},
			{5, {'j', 'k', 'l'}},
			{6, {'m', 'n', 'o'}},
			{7, {'p', 'q', 'r', 's'}},
			{8, {'t', 'u', 'v'}},
			{9, {'w', 'x', 'y', 'z'}},
		};
		auto ans = recurse(digits, 0, mp);
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	auto ans = s.letterCombinations("23");
	debug(ans);
	return 0;
}
