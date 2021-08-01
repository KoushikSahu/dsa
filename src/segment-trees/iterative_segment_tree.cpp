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
    Created: 01 August 2021 Sun 19:09:06
*/

const int nxm = 1e5 + 5;
int n;
int st[2*nxm];

/*
    caveats:
    query is for range [l, r)
    do a r++ after taking query input
*/

void build(){
    for(int i=n-1; i>0; i--){
        st[i] = st[i<<1] + st[i<<1|1];
    }
}

void update(int idx, int val){
    for(st[idx+=n]=val; idx>1; idx >>= 1) st[idx>>1] = st[idx] + st[idx|1];
}

int query(int l, int r){
    int res = 0;
    for(l += n, r += n; l<r; l>>=1, r>>=1){
        if(l&1) res += st[l++];
        if(r&1) res += st[--r];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>st[n+i];
    }
    build();
    update(4, 5);
    for(int i=0; i<2*n; i++) cout<<st[i]<<' ';
    cout<<'\n';
    cout<<query(1, 5)<<'\n';
    return 0;
}