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
  Created: 2022-03-13 11:10 IST
*/

template <typename T>
class Row{
  public:
    Row(){ }

    Row(int len) : n(len){
      assert(len>0);
      a = new int[len];
      for(int i=0; i<len; i++) a[i] = 0;
    }

    T& operator[](int idx){
      assert(idx>=0 && idx<n);
      return a[idx];
    }

  private:
    T* a;
    int n;

};

template <typename T>
class Matrix{
  public:
    int n, m;

    Matrix(int row, int col, bool identity=false) : n(row), m(col){
      if(identity) assert(row == col);
      a = new Row<T>[row];
      for(int i=0; i<row; i++) a[i] = Row<T>(col);
      if(identity) for(int i=0; i<row; i++) a[i][i] = 1;
    }

    Row<T>& operator[](int idx){
      return a[idx];
    }

    Matrix operator*(Matrix b){
      assert(m == b.n);
      Matrix<T> product(n, b.m);
      for(int i=0; i<n; i++){
        for(int j=0; j<b.m; j++){
          for(int k=0; k<m; k++){
            product[i][j] += (a[i][k]*b[k][j]);
          }
        }
      }
      return product;
    }

    void show(){
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          cout<<a[i][j]<<" ";
        }
        cout<<"\n";
      }
    }

  private:
    Row<T>* a;

};

template <typename T>
Matrix<T> matpow(Matrix<T> m, int p){
  Matrix<T> ans(m.n, m.m, true);
  while(p){
    if(p%2) ans = ans * m;
    m = m * m;
    p /= 2;
  }
  return ans;
}

void solve(){
  const int nxm = 1e5+5;
  int n, k, a[nxm], p[nxm];
  cin>>n>>k;
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<n; i++) cin>>p[i];
  Matrix<int> perm(n, n, false);
  for(int i=0; i<n; i++){
    perm[i][p[i]] = 1;
  }
  perm = matpow(perm, k);
  Matrix<int> aa(1, n, false);
  for(int i=0; i<n; i++) aa[0][i] = a[i];
  aa = aa*perm;
  for(int i=0; i<n; i++) cout<<aa[0][i]<<' ';
  cout<<'\n';
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

