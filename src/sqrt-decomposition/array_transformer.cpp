#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
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
    Created: 09 August 2021 Mon 10:49:00
*/

const int nxm = 3e5+5;
int n, m, u, a[nxm], b[nxm], l, r, v, p, blk_sz;

int query(int l, int r, int v){
    int b_l = l/blk_sz;
    int b_r = r/blk_sz;
    int ans = 0;
    if(b_l == b_r){
        return count_if(a+l, a+r+1, [&](int x){return x<v;});
    }
    for(int i=l; i<=(b_l+1)*blk_sz-1; i++){
        if(a[i]<v) ans++;
    }
    for(int i=b_l+1; i<=b_r-1; i++){
        ans += (lower_bound(b+i*blk_sz, b+(i+1)*blk_sz, v)-b-i*blk_sz);
    }
    for(int i=b_r*blk_sz; i<=r; i++){
        if(a[i]<v) ans++;
    }
    return ans;
}

void update(int idx, int new_val){
    a[idx] = new_val;
    int blk_idx = idx/blk_sz;
    vint tmp;
    for(int i=blk_idx*blk_sz; i<min((blk_idx+1)*blk_sz, n); i++) tmp.push_back(a[i]);
    sort(all(tmp));
    for(int i=blk_idx*blk_sz, j=0; i<min((blk_idx+1)*blk_sz, n); i++, j++) b[i] = tmp[j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n>>m>>u;
    for(int i=0; i<n; i++) cin>>a[i];
    copy(a, a+n, b);
    blk_sz = (int)sqrt(n+.0) + 1;
    for(int i=0; i<n; i+=blk_sz){
        sort(b+i, b+min(i+blk_sz, n));
    }
    while(m--){
        cin>>l>>r>>v>>p;
        l--, r--, p--;
        int k = query(l, r, v);
        update(p, (1ll*k*u)/(r-l+1));
    }
    for(int i=0; i<n; i++) cout<<a[i]<<'\n';
    return 0;
}