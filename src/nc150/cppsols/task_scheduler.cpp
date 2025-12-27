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
        Created: 12:41:52 PM(12:41:52) IST(+05:30) 27-12-2025 Sat
*/

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    array<int, 26> task_cnt;
    task_cnt.fill(0);
    for (const auto &task : tasks) {
      task_cnt[task - 'A'] += 1;
    }
    array<int, 26> wait_time;
    wait_time.fill(0);
    int ans = 0, curr_wait_time = 0;
    bool tasks_left = true;
    while (tasks_left) {
      // debug(task_cnt);
      for (int i = 0; i < 26; i++) {
        wait_time[i] -= 1;
        wait_time[i] = max(wait_time[i], 0);
      }

      tasks_left = false;
      curr_wait_time = INT_MAX;

      int mx_task_cnt = INT_MIN, mx_task = -1;
      for (int i = 0; i < 26; i++) {
        if (task_cnt[i] > 0 && wait_time[i] <= 0) {
          if (task_cnt[i] > mx_task_cnt) {
            mx_task_cnt = task_cnt[i];
            mx_task = i;
          }
        }
      }

      if (mx_task != -1) {
        task_cnt[mx_task] -= 1;
        wait_time[mx_task] = n + 1;
      }

      for (int i = 0; i < 26; i++) {
        if (task_cnt[i] > 0) {
          tasks_left = true;
        }
      }

      ans += 1;
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
    Solution s;
    vector<char> tasks1{'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(tasks1, 2) << '\n';
    cout << s.leastInterval(tasks1, 3) << '\n';
    vector<char> tasks2{'A', 'C', 'A', 'B', 'D', 'B'};
    cout << s.leastInterval(tasks2, 1) << '\n';
    vector<char> tasks3{'A', 'A', 'A', 'B', 'B', 'B',
                        'C', 'C', 'C', 'D', 'D', 'E'};
    cout << s.leastInterval(tasks3, 2) << '\n';
  }
  return 0;
}
