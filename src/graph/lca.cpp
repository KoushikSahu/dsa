#include <bits/stdc++.h>
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
  Created: 2022-02-13 11:59 IST
*/

void dfs(int root,
    int n,
    vector<int>* g,
    vector<int>& height,
    vector<int>& first,
    vector<int>& euler,
    bool* visited,
    int ht = 0
  ){
  visited[root] = true;
  height[root] = ht;
  first[root] = euler.size();
  euler.push_back(root);
  for(int neighbor: g[root]){
    if(!visited[neighbor]){
      dfs(neighbor, n, g, height, first, euler, visited, ht+1);
      euler.push_back(root);
    }
  }
}

void build(int root, int low, int high, const vector<int>& euler, vector<int>& st, const vector<int>& height){
  if(low == high){
    st[root] = euler[low];
    return ;
  }
  int mid = low + (high-low) / 2;
  build(2*root+1, low, mid, euler, st, height);
  build(2*root+2, mid+1, high, euler, st, height);
  st[root] = (height[st[2*root+1]] < height[st[2*root+2]]) ? st[2*root+1] : st[2*root+2];
}

int query(int root, int low, int high, int l, int r, const vector<int>& st, const vector<int>& height){
  if(low>r || high<l) return -1;
  else if(l<=low && r>=high) return st[root];
  int mid = low + (high-low) / 2;
  int left = query(2*root+1, low, mid, l, r, st, height);
  int right = query(2*root+2, mid+1, high, l, r, st, height);
  if(left==-1 || right==-1) return (left == -1 ? right : left);
  return height[left] < height[right] ? left : right;
}

int lca(int v1, int v2, int euler_size, const vector<int>& first, const vector<int>& st, const vector<int>& height){
  int first1 = first[v1];
  int first2 = first[v2];
  if(first1 > first2) swap(first1, first2);
  return query(0, 0, euler_size-1, first1, first2, st, height);
}

void solve(){
  int n, m;
  cin>>n>>m;

  vector<int> g[n];
  int u, v;
  for(int i=0; i<n; i++){
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> height(n), first(n), euler;
  bool visited[n];
  fill_n(visited, n, false);
  dfs(0, n, g, height, first, euler, visited);

  int euler_size = euler.size();
  vector<int> st(4*euler_size);
  build(0, 0, euler_size-1, euler, st, height);
  cout<<lca(4, 5, euler_size, first, st, height)<<'\n';
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

