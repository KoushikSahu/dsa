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
        Created: 03:29:05 PM(15:29:05) IST(+05:30) 26-10-2025 Sun
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reverseLinkedList(ListNode *head, ListNode *end, ListNode *prev) {
    if (head == nullptr) {
      return;
    }
    ListNode *curr = head, *nxt = head->next;
    while (curr != end) {
      curr->next = prev;
      prev = curr;
      curr = nxt;
      if (nxt != nullptr) {
        nxt = nxt->next;
      }
    }
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *start = head, *prev = nullptr, *new_head = nullptr, *last_start = nullptr;
    while (true) {
      ListNode *end = start, *end_prev = nullptr;
      bool break_while_loop = false;
      for (int i = 0; i < k; i++) {
        if (end != nullptr) {
          end_prev = end;
          end = end->next;
        } else {
          break_while_loop = true;
          break;
        }
      }
      if (break_while_loop) {
        break;
      } else if(new_head == nullptr) {
        new_head = end_prev;
      }
      reverseLinkedList(start, end, end);
      if(last_start != nullptr) {
        last_start->next = end_prev;
      }
      prev = start;
      last_start = start;
      start = end;
    }
    return new_head;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solution s;
  s.reverseKGroup(new ListNode(1), 1);
  return 0;
}
