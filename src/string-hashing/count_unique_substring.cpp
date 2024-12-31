#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000009
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
    Created: 24 August 2021 Tue 11:26:02
*/

string s;

ll power(ll n, ll k){
    ll ans = 1;
    while(k){
        if(k%2){
            ans *= n;
            ans %= MOD;
        }
        n *= n;
        n %= MOD;
        k /= 2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>s;
    int n = sz(s);
    int p = 31;
    vll pow_p(n+1, 0);
    pow_p[0] = 1;
    for(int i=1; i<=n; i++){
        pow_p[i] = pow_p[i-1]*p;
        pow_p[i] %= MOD;
    }
    vll pref(sz(s), 0);
    pref[0] = (s[0]-'a'+1) * pow_p[0];
    for(int i=1; i<n; i++){
        pref[i] = pref[i-1] + (s[i]-'a'+1)*pow_p[i];
        pref[i] %= MOD;
    }
    ll ans = 0;
    for(int l=1; l<=n; l++){
        set<ll> hs;
        for(int i=0; i<=n-l; i++){
            ll hash = i==0 ? pref[i+l-1] : pref[i+l-1]-pref[i-1];
            hash %= MOD;
            if(hash<0) hash += MOD;
            hash *= power(pow_p[i], MOD-2);
            hash %= MOD;
            hs.insert(hash);
        }
        ans += sz(hs);
    }
    cout<<ans<<'\n';
    return 0;
}
