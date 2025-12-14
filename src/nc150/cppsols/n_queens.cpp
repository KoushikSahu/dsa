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
	Created: 11:00:33 PM(23:00:33) IST(+05:30) 11-12-2025 Thu
*/

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> pos(n, string(n, '.'));
		vector<vector<bool>> legal(n, vector<bool>(n, true));
		vector<vector<bool>> tried(n, vector<bool>(n, false));
		vector<vector<string>> ans;
		solveNQueens(0, n, pos, legal, tried, ans);
		return ans;
	}

private:
	void solveNQueens(int row, int n, vector<string>& pos, vector<vector<bool>>& legal, vector<vector<bool>> tried, vector<vector<string>>& ans) {
		int sz = (int)pos.size();
		if(n == 0) {
			ans.push_back(pos);
			return;
		}
		for(int j=0; j<sz; j++){
			if(pos[row][j] == '.' && legal[row][j] && !tried[row][j]) {
				pos[row][j] = 'Q';
				tried[row][j] = true;
				vector<vector<bool>> legal_copy = legal;
				for(int k=0; k<sz; k++) {
					legal_copy[k][j] = false;
					legal_copy[row][k] = false;
				}
				int rd[4] = {-1, -1, 1, 1};
				int cd[4] = {-1, 1, -1, 1};
				auto valid = [](int x, int y, int szz) {
					return x >= 0 && x < szz && y >= 0 && y < szz;
				};
				for(int k=0; k<4; k++) {
					int r = row;
					int c = j;
					while(valid(r + rd[k], c + cd[k], sz)) {
						legal_copy[r + rd[k]][c + cd[k]] = false;
						r = r + rd[k];
						c = c + cd[k];
					}
				}
				solveNQueens(row + 1, n-1, pos, legal_copy, tried, ans);
				pos[row][j] = '.';
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
		auto ans = s.solveNQueens(9);
		for(auto sol: ans){
			for(auto row: sol){
				cout << row << '\n';
			}
			cout << '\n';
		}
	}
	return 0;
}
