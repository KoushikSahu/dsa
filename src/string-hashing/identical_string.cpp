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
    Created: 20 August 2021 Fri 11:52:51
*/

const int nxm = 1e5+5;
int n;
string s[nxm];

ll power(int n, int k, int p){
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

ll compute_hash(string s){
    int len = s.length();
    ll hash = 0;
    for(int i=0; i<len; i++){
        hash += 1ll*(s[i]-'a'+1)*power(31, i, MOD);
        hash %= MOD;
    }
    return hash;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) cin>>s[i];
    vector<pair<ll, int>> hashes;
    for(int i=0; i<n; i++){
        hashes.push_back({compute_hash(s[i]),  i});
    }
    sort(all(hashes));
    vector<vector<int>> ans;
    ans.push_back({});
    ans.back().push_back(hashes[0].second);
    for(int i=1; i<n; i++){
        pair<ll, int> p = hashes[i];
        if(p.first != hashes[i-1].first) ans.push_back({});
        ans.back().push_back(p.second);
    }
    for(vint a: ans){
        for(int i: a){
            cout<<s[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}