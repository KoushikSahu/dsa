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
    Created: 08 August 2021 Sun 11:54:34
*/

const int p = 31;

size_t power(int n, int m, int mod){
    size_t ans = 1;
    while(m){
        if(m%2){
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
        m /= 2;
    }
    return ans;
}

struct StringHash {
    size_t operator()(const string& s) const {
        size_t hash = 0;
        int len = sz(s);
        for(int i=0; i<len; i++){
            hash += (s[i]-'a'+1)*power(p, i, MOD);
            hash %= MOD;
        }
        return hash;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    unordered_map<string, int, StringHash> mp;
    StringHash sh;
    mp["abcd"] = 20;
    cout<<sh("abcd")<<'\n';
    mp["sldj"] = 19;
    cout<<sh("sldj")<<'\n';
    mp["itu"] = 18;
    cout<<sh("itu")<<'\n';
    mp["ljfbn"] = 15;
    cout<<sh("ljfbn")<<'\n';
    mp["lkdj"] = 50;
    cout<<sh("lkdj")<<'\n';
    for(pair<string, int> pr: mp) cout<<pr.first<<' '<<pr.second<<'\n';
    return 0;
}