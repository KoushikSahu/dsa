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
    Created: 07 August 2021 Sat 11:05:36
*/

int block_size = 1e3+5;

struct Query{
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l/block_size, r) < make_pair(other.l/block_size, r);
    }
};

const int nxm = 1e5+5;
int n, a[nxm], q, l, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>q;
    vector<Query> queries(q);
    for(int i=0; i<q; i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].idx = i;
    }
    sort(all(queries));
    vector<int> ans(q);
    int sum = 0;
    int curr_l = 0, curr_r = -1;
    for(Query query: queries){
        while(curr_l < query.l){
            sum -= a[curr_l];
            curr_l++;
        }
        while(curr_l > query.l){
            curr_l--;
            sum += a[curr_l];
        }
        while(curr_r < query.r){
            curr_r++;
            sum += a[curr_r];
        }
        while(curr_r > query.r){
            sum -= a[curr_r];
            curr_r--;
        }
        ans[query.idx] = sum;
    }
    for(int i: ans) cout<<i<<' ';
    cout<<'\n';
    return 0;
}