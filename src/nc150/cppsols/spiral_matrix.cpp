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
	Created: 11:25:21 AM(11:25:21) IST(+05:30) 14-12-2025 Sun
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int n = (int)matrix.size();
		int m = (int)matrix[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
		
		function<bool(int, int)> is_valid = [&n, &m](int x, int y) {
			return x >= 0 && x < n && y >= 0 && y < m;
		};
		
		vector<int> dr {0, 1, 0, -1};
		vector<int> dc {1, 0, -1, 0};

		int r = 0, c = -1;
		vector<int> ans(n * m);
		int curr_idx = 0;
		while(true) {
			bool something_changed = false;
			for(int i = 0; i < 4; i++) {
				while(is_valid(r + dr[i], c + dc[i]) && !seen[r + dr[i]][c + dc[i]]) {
					r = r + dr[i];
					c = c + dc[i];
					seen[r][c] = true;
					ans[curr_idx++] = matrix[r][c];
					something_changed = true;
				}
			}
			if(!something_changed) {
				break;
			}
		}

		return ans;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		vector<vector<int>> a {{ 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 }};
		vector<int> ans = s.spiralOrder(a);
		debug(ans);
	}
	return 0;
}
