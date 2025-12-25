#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <array>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
	Created: 12:12:02 PM(12:12:02) IST(+05:30) 25-12-2025 Thu
*/

/*
* maximise (j - i + 1) * (min(a[j], a[j-1]....a[i]))
*/

class Solution {
public:
    int largestRectangleAreaTwoMonotonicStacks(vector<int>& heights) {
		int n = (int)heights.size();
		stack<int> st;
		array<int, (int)1e5 + 5> pse, nse;
		fill(pse.begin(), pse.begin() + n, 0);
		fill(nse.begin(), nse.begin() + n, 0);
		for (int i = 0; i < n; i++) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			pse[i] = st.empty() ? -1 : st.top();
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			nse[i] = st.empty() ? n : st.top();
			st.push(i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			// debug(heights[i], pse[i], nse[i], nse[i] - pse[i] - 1);
			ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
		}
		return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
		int n = (int)heights.size();
		stack<int> st;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				int tp = st.top();
				st.pop();

				int width = st.empty() ? i : i - st.top() - 1;
				ans = max(ans, width * heights[tp]);
			}
			st.push(i);
		}
		while (!st.empty()) {
			int tp = st.top();
			st.pop();

			int width = st.empty() ? n : n - 1 - st.top();
			ans = max(ans, width * heights[tp]);
		}
		return ans;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		vector<int> heights { 2, 1, 5, 6, 2, 3 };
		cout << s.largestRectangleArea(heights) << '\n';
	}
	return 0;
}
