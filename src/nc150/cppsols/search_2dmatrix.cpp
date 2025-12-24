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
	Created: 11:10:03 PM(23:10:03) IST(+05:30) 24-12-2025 Wed
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = (int)matrix.size(), m = (int)matrix[0].size();
		int low = 0, high = n;
		while (low < high) {
			int mid = low + ((high - low) / 2);
			if (matrix[mid][0] <= target) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		if (low == 0) return false;
		int row = low - 1;
		low = 0, high = m - 1;
		while (low < high) {
			int mid = low + ((high - low) / 2);
			if (matrix[row][mid] < target) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		if (low == m) return false;
		return matrix[row][low] == target;
    }

    bool searchMatrixSingleBinarySearch(vector<vector<int>>& matrix, int target) {
		int n = (int)matrix.size(), m = (int)matrix[0].size();
		int low = 0, high = n * m;
		while (low < high) {
			int mid = low + (high - low) / 2;
			int row = mid / m;
			int col = mid - (row * m);
			if (matrix[row][col] >= target) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		if (low == n*m) return false;
		int row = low / m;
		int col = low - (row * m);
		return matrix[row][col] == target;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		vvint matrix {{ 1,3,5,7 },{ 10,11,16,20 },{ 23,30,34,60 }};
		cout << s.searchMatrixSingleBinarySearch(matrix, 7) << '\n';
	}
	return 0;
}
