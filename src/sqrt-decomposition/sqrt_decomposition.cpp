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
    Created: 05 August 2021 Thu 10:55:34
*/

const int nxm = 1e5+5, nxmm = 1e3+5;
int n, a[nxm], b[nxmm], q, l, r;

void build(int len){
    fill_n(b, len, 0);
    for(int i=0; i<n; i++){
        b[i/len] += a[i];
    }
}

// has a lot of divide operations
// making this query slow
int query(int l, int r, int len){
    int res = 0;
    for(int i=l; i<=r; ){
        if(i%len==0 && i+len-1<=r){
            res += b[i/len];
            i += len;
        }else{
            res += a[i];
            i++;
        }
    }
    return res;
}

// to have faster query
// we calculate the indices in b
int fast_query(int l, int r, int len){
    int res = 0;
    int b_l = l/len, b_r = r/len;
    if(b_l == b_r){
        return accumulate(a+l, a+r+1, 0);
    }else{
        for(int i=l; i<=(b_l+1)*len-1; i++) res += a[i];
        for(int i=b_l+1; i<=b_r-1; i++) res += b[i];
        for(int i=b_r*len; i<=r; i++) res += a[i];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    int len = sqrt(n+.0) + 1;
    build(len);
    cin>>q;
    while(q--){
        cin>>l>>r;
        int res = fast_query(l, r, len);
        cout<<res<<'\n';
    }
    return 0;
}
