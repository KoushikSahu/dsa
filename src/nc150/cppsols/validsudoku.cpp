#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)                                                            \
  cerr << "[" << #x << "] = [";                                                \
  _print(x)
#else
#define debug(x...)
#endif

/*
        Author: Koushik Sahu
        Created: 09:00:50 AM(09:00:50) IST(+05:30) 31-10-2025 Fri
*/

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int n = (int)board.size();
    int m = (int)board[0].size();
    bool ans = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] != '.') {
          for (int k = 0; k < i; k++) {
            ans &= (board[k][j] != board[i][j]);
          }
          for (int k = i + 1; k < n; k++) {
            ans &= (board[k][j] != board[i][j]);
          }
          for (int k = 0; k < j; k++) {
            ans &= (board[i][k] != board[i][j]);
          }
          for (int k = j + 1; k < n; k++) {
            ans &= (board[i][k] != board[i][j]);
          }
          int ns = (i / 3) * 3;
          int ne = (i / 3 + 1) * 3;
          int ms = (j / 3) * 3;
          int me = (j / 3 + 1) * 3;
          for (int k = ns; k < ne; k++) {
            for (int l = ms; l < me; l++) {
              if (k != i && l != j) {
                ans &= (board[k][l] != board[i][j]);
              }
            }
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  // cin>>T;
  while (T--) {
    solve();
  }
  return 0;
}
