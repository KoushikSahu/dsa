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
	Created: 10:55:00 AM(10:55:00) IST(+05:30) 25-12-2025 Thu
*/

struct Position {
	int i, j;
	
	Position(int i, int j): i(i), j(j) {} 

	bool is_valid(int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		bool ans = false;
		int n = board.size();
		int m = (int)board[0].size();
		vector<vector<bool>> seen(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans |= recurse(Position(i, j), seen, 0, board, word);
			}
		}
		return ans;
    }

private:
	bool recurse(Position p, vector<vector<bool>>& seen, int idx, const vector<vector<char>>& board, const string& word) {
		if (idx == word.length()) {
			return true;
		}
		int n = board.size();
		int m = board[0].size();
		if (!p.is_valid(n, m) || seen[p.i][p.j]) {
			return false;
		}
		if (board[p.i][p.j] != word[idx]) {
			return false;
		}
		bool is_possible = false;
		int dr[] = {-1, 1, 0, 0};
		int dc[] = {0, 0, -1, 1};
		seen[p.i][p.j] = true;
		for (int i = 0; i < 4; i++) {
			int r = p.i + dr[i];
			int c = p.j + dc[i];
			Position new_p = Position(r, c);
			is_possible |= recurse(new_p, seen, idx + 1, board, word);
		}
		seen[p.i][p.j] = false;
		return is_possible;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		vector<vector<char>> board = {{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}};
		string word = "aaaaaaaaaaaaa";
		cout << s.exist(board, word) << '\n';
	}
	return 0;
}
