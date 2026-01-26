#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define INF 1000000005
#define NEG_INF -1000000005
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

/*
Author: Koushik Sahu
Created: 10:43:37 AM(10:43:37) IST(+05:30) 26-01-2026 Mon
 */

class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
		if (bottom.empty()) {
			bottom.push(num);
			return;
		}
		if (top.size() == bottom.size()) {
			if (num <= top.top()) {
				bottom.push(num);
			} else {
				int t = top.top();
				top.pop();
				bottom.push(t);
				top.push(num);
			}
			return;
		}
		// bottom.size() = top.size() + 1
		if (num <= bottom.top()) {
			int b = bottom.top();
			bottom.pop();
			top.push(b);
			bottom.push(num);
		} else {
			top.push(num);
		}
    }
    
    double findMedian() {
		if (bottom.size() > top.size()) {
			return bottom.top();
		}
		double t = (double)top.top();
		double b = (double)bottom.top();
		double ans = (t + b) / 2;
		return ans;
    }

private:
	priority_queue<int> bottom;
	priority_queue<int, vector<int>, greater<int>> top;
};

void solve(){
	MedianFinder mf;

	mf.addNum(40);
	cout << setprecision(6) << mf.findMedian() << '\n';
	mf.addNum(12);
	cout << setprecision(6) << mf.findMedian() << '\n';
	mf.addNum(16);
	cout << setprecision(6) << mf.findMedian() << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
