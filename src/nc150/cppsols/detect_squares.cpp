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
	Created: 08:37:36 PM(20:37:36) IST(+05:30) 26-12-2025 Fri
*/

class DetectSquares {
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
		pointCount[point] += 1;
    }
    
    int count(vector<int> point) {
		int x = point[0];
		int y = point[1];
		int cnt = pointCount[point];
		int ans = 0;
		for (const auto& pt1: pointCount) {
			int x1 = pt1.first[0];
			int y1 = pt1.first[1];
			int cnt1 = pt1.second;
			if (x1 == x && y1 != y) {
				for (const auto& pt2: pointCount) {
					int x2 = pt2.first[0];
					int y2 = pt2.first[1];
					int cnt2 = pt2.second;
					if (x2 != x && y2 == y) {
                        if (abs(y1 - y) == abs(x2 - x)) {
                            vector<int> pt3 {x2, y1};
                            int cnt3 = pointCount[pt3];
                            ans += (cnt1 * cnt2 * cnt3);
                        }
					}
				}
			}
		}
		return ans;
    }

private:
	map<vector<int>, int> pointCount;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
