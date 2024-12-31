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
  Created: 2022-04-04 23:54 IST
*/

template <typename T>
class Row{
  public:
    Row(){ }

    Row(int len) : n(len){
      assert(len>0);
      n = len;
      a = new int[len];
      for(int i=0; i<len; i++) a[i] = 0;
    }

    T& operator[](int idx){
      assert(idx>=0 && idx<n);
      return a[idx];
    }

    int size(){
      return n;
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

    int size(){
      return n;
    }

  private:
    Row<T>* a;

};

Matrix<int> translate(int x, int y){
  Matrix<int> tfms(3, 3, false);
  tfms[0][0] = 1;
  tfms[2][0] = x;
  tfms[1][1] = 1;
  tfms[2][1] = y;
  tfms[2][2] = 1;
  return tfms;
}

Matrix<int> scale(int x, int y){
  Matrix<int> tfms(2, 2, false);
  tfms[0][0] = x;
  tfms[1][1] = y;
  return tfms;
}

Matrix<int> rotate(double theta){
  Matrix<int> tfms(2, 2, false);
  tfms[0][0] = cos(theta);
  tfms[0][1] = sin(theta);
  tfms[1][0] = -sin(theta);
  tfms[1][1] = cos(theta);
  return tfms;
}

Matrix<int> binexpo(Matrix<int> m, int k){
  Matrix<int> ans(2, 2, true);
  while(k){
    if(k%2) ans = ans * m;
    m = m*m;
    k /= 2;
  }
  return ans;
}

void solve(){
  int x, y, k;
  cin>>x>>y>>k;
  Matrix<int> tfms = rotate(M_PI/2);
  tfms = binexpo(tfms, k);
  Matrix<int> pt(1, 2, false);
  pt[0][0] = x, pt[0][1] = y;
  pt = pt*tfms;
  cout<<pt[0][0]<<' '<<pt[0][1]<<'\n';
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

