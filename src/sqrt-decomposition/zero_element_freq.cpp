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
    Created: 05 August 2021 Thu 11:52:00
*/

const int nxm = 1e5+5, nxmm=1e3+5;
int n, a[nxm], b[nxmm], q, l, r;

void build(int len){
    fill_n(b, len, 0);
    for(int i=0; i<=n-1; i++){
        b[i/len] += (a[i] == 0);
    }
}

int query(int left, int right, int len){
    int res = 0;
    int c_l = left/len, c_r = right/len;
    if(c_l == c_r) return count(a+left, a+right+1, 0);
    for(int i=left; i<=(c_l+1)*len-1; i++) res += (a[i] == 0);
    for(int i=c_l+1; i<=c_r-1; i++) res += b[i];
    for(int i=c_r*len; i<=right; i++) res += (a[i] == 0);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    int len = (int)sqrt(n+.0) + 1;
    build(len);
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<query(l, r, len)<<' ';
    }
    cout<<'\n';
    return 0;
}