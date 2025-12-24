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
	Created: 08:50:44 PM(20:50:44) IST(+05:30) 24-12-2025 Wed
*/

class Solution {
public:
    void setZeroesBitSet(vector<vector<int>>& matrix) {
        int n = (int)matrix.size(), m = (int)matrix[0].size();
		const int nxm = 205;
        bitset<nxm> rows;
        bitset<nxm> cols;
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 0) {
					rows.set(i);
					cols.set(j);
				}
			}
        }
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (rows[i] || cols[j]) {
					matrix[i][j] = 0;
				}
			}
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = (int)matrix.size(), m = (int)matrix[0].size();
		int col0 = 1;
		for (int i = 0; i < n; i++) {
			if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < m; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 1; j--) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
		}
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		vector<vector<int>> matrix {{ 0,1,2,0 },{ 3,4,5,2 },{ 1,3,1,5 }};
		s.setZeroes(matrix);
		for (auto rows: matrix) {
			for (int val: rows) {
				cout << val << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
