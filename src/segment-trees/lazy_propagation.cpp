#include <bits/stdc++.h>
#include <cwchar>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
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
  Created: 2022-01-19 12:52 IST
*/

class SegmentTree {
  public:
    SegmentTree(int len, vint arr){
      a = new int[len];
      st = new int[4*len];
      lazy = new int[4*len];
      n = len;
      fill(st, st+4*len, 0);
      fill(lazy, lazy+4*len, 0);
      for(int i=0; i<len; i++) a[i] = arr[i];
      _build(0, 0, len-1);
    }

    SegmentTree(int len, int* arr){
      a = new int[len];
      st = new int[4*len];
      lazy = new int[4*len];
      n = len;
      fill(st, st+4*len, 0);
      fill(lazy, lazy+4*len, 0);
      for(int i=0; i<len; i++) a[i] = arr[i];
      _build(0, 0, len-1);
    }

    int query(int l, int r){
      return _query(l, r, 0, 0, n-1);
    }

    void update(int idx, int val){
      _update(idx, val, 0, 0, n-1);
    }

    void update(int l, int r, int val){
      _update(l, r, val, 0, 0, n-1);
    }

  private:
    int n, *a, *st, *lazy; 

    void _build(int root, int l, int r){
      if(l==r){
        st[root] = a[l];
        return ;
      }
      int mid = l + ((r-l) / 2);
      _build(2*root+1, l, mid);
      _build(2*root+2, mid+1, r);
      st[root] = st[2*root+1] + st[2*root+2];
    }

    void _update(int idx, int val, int root, int l, int r){
      if(lazy[root]){
        st[root] += (r-l+1)*lazy[root];
        if(l!=r){
          lazy[2*root+1] += lazy[root];
          lazy[2*root+2] += lazy[root];
        }
        lazy[root] = 0;
      }
      if(l==r){
        st[root] = val;
        return ;
      }
      int mid = l + ((r-l) / 2);
      if(idx<=mid) _update(idx, val, 2*root+1, l, mid);
      if(idx>mid) _update(idx, val, 2*root+2, mid+1, r);
      st[root] = st[2*root+1] + st[2*root+2];
    }

    void _update(int l, int r, int val, int root, int lt, int rt){
      if(lazy[root]){
        st[root] += (rt-lt+1)*lazy[root];
        if(lt!=rt){
          lazy[2*root+1] += lazy[root];
          lazy[2*root+2] += lazy[root];
        }
        lazy[root] = 0;
      }
      if(l>rt || r<lt) return ;
      else if(l<=lt && rt<=r){
        st[root] += (rt-lt+1)*val;
        if(lt!=rt){
          lazy[2*root+1] += val;
          lazy[2*root+2] += val;
        }
        return ;
      }
      int mid = lt + ((rt-lt) / 2);
      _update(l, r, val, 2*root+1, lt, mid);
      _update(l, r, val, 2*root+2, mid+1, rt);
      st[root] = st[2*root+1] + st[2*root+2];
    }

    int _query(int l, int r, int root, int lt, int rt){
      if(lazy[root]){
        st[root] += (rt-lt+1)*lazy[root];
        if(lt!=rt){
          lazy[2*root+1] += lazy[root];
          lazy[2*root+2] += lazy[root];
        }
        lazy[root] = 0;
      }
      if(r<lt || l>rt) return 0;
      else if(l<=lt && r>=rt){
        return st[root];
      } 
      int mid = lt + ((rt-lt) / 2);
      return _query(l, r, 2*root+1, lt, mid) + _query(l, r, 2*root+2, mid+1, rt);
    }
};

void solve(){
  int a[] = {2, 4, 5, 6, 1, 6, 6, 7};
  int n = 8; 
  SegmentTree st(n, a);
  cout<<st.query(1, 5)<<'\n';
  st.update(1, 3, 4);
  cout<<st.query(2, 4)<<'\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T=1;
  //cin>>T;
  while(T--){
    solve();
  }
  return 0;
}

