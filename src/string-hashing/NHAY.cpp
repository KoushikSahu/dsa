#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
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

const int nxm = 1e6+5;
int t;
string n, h;
const int p = 31;

ll power(ll n, ll k){
	ll res = 1;
	while(k){
		if(k%2){
			res *= n;
			res %= MOD;
		}
		n *= n;
		n %= MOD;
		k /= 2;
	}
	return res;
}

int main(){
	while(scanf("%d", &t)!=EOF){
		cin>>n>>h;
		int szh = sz(h);
		int l = sz(n);
		vll pref(szh, 0);
		vll pow_p(szh+1, 0);
		pow_p[0] = 1;
		for(int i=1; i<=szh; i++) pow_p[i] = (pow_p[i-1]*p)%MOD;
		pref[0] = (h[0]-'a'+1);
		for(int i=0; i<szh; i++){
			pref[i] = (pref[i-1] + (h[i]-'a'+1)*pow_p[i])%MOD;
		}
		ll hs = 0;
		for(int i=0; i<l; i++){
			hs += (n[i]-'a'+1)*pow_p[i];
			hs %= MOD;
		}
		for(int s=0; s<=szh-l; s++){
			ll hsh = s==0 ? pref[s+l-1] : pref[s+l-1] - pref[s-1];
			hsh%=MOD;
			if(hsh<0) hsh += MOD;
			hsh *= power(pow_p[s], MOD-2);
			hsh %= MOD;
			if(hsh == hs){
				cout<<s<<'\n';
			}
		}
	}
    return 0;
}


