#include <bits/stdc++.h>
#include <cassert>
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
	Created: 11:41:33 PM(23:41:33) IST(+05:30) 20-12-2025 Sat
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = (int)word1.size(), n2 = (int)word2.size();
		array<array<int, 505>, 505> dp;
		fill_n(&dp[0][0], (n1 + 1) * (n2 + 1), 0);
		for(int i=0; i<=n1; i++){
			dp[i][0] = i;
		}
		for(int j=0; j<=n2; j++){
			dp[0][j] = j;
		}
		for(int i=1; i<=n1; i++){
			for(int j=1; j<=n2; j++){
				if(word1[i-1] == word2[j-1]){
					dp[i][j] = dp[i-1][j-1];
				} else {
					dp[i][j] = min({dp[i-1][j] + 1, dp[i-1][j-1] + 1, dp[i][j-1] + 1});
				}
			}
		}
		return dp[n1][n2];
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		assert(s.minDistance("horse", "ros") == 3 && "testcase #1 failed");
		assert(s.minDistance("intention", "execution") == 5 && "testcase #2 failed");
	}
	return 0;
}
