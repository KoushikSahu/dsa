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
    Created: 20 August 2021 Fri 12:23:59
*/

const int nxm = 1e5+5;
string s;
int q, l, r;
vll prefix(nxm);

ll power(ll n, int k, int p){
    ll ans = 1;
    while(k){
        if(k%2){
            ans *= n;
            ans %= p;
        } 
        n *= n;
        n %= p;
        k /= 2;
    }
    return ans;
}

ll modular_multiplicative_inverse(ll a){
    return power(a, MOD-2, MOD);
}

ll substring_hash(int i, int j){
    assert(j>=i);
    if(i==0) return prefix[j];
    ll tmp = prefix[j] - prefix[i-1];
    tmp %= MOD;
    if(tmp<0) tmp += MOD;
    tmp *= modular_multiplicative_inverse(power(31, i, MOD));
    tmp %= MOD;
    return tmp;
}

ll compute_hash(string s){
    int n = sz(s);
    ll hash = 0;
    for(int i=0; i<n; i++){
        hash += (s[i]-'a'+1)*power(31, i, MOD);
        hash %= MOD;
    }
    return hash;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>s;
    prefix[0] = s[0]-'a'+1;
    int n = s.length();
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + (s[i]-'a'+1)*power(31, i, MOD);
        prefix[i] %= MOD;
    }
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<substring_hash(l, r)<<'\n';
        cout<<compute_hash(s.substr(l, r-l+1))<<'\n';
    }
    return 0;
}
