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
	Created: 09:35:01 PM(21:35:01) IST(+05:30) 16-01-2026 Fri
*/

class MonotonicQueue {
public:
	void push(int x) {
		while (!dq.empty() && dq.back() < x) {
			dq.pop_back();
		}
		dq.push_back(x);
	}

	int peek() {
		return dq.front();
	}

	void pop(int x) {
		if (dq.front() == x) {
			dq.pop_front();
		}
	}

private:
	deque<int> dq;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = (int)nums.size();

		int end = 0;
		vector<int> ans;
		MonotonicQueue mq;
		for (; end < k; end++) {
			mq.push(nums[end]);
		}
		ans.push_back(mq.peek());

		end -= 1;

		while (end < n - 1) {
			int start = end - k + 1;
			mq.pop(nums[start]);

			start += 1;
			end += 1;
			
			mq.push(nums[end]);
			ans.push_back(mq.peek());
		}

		return ans;
    }
};

void solve(){
	Solution s;

	vector<int> nums {1,3,-1,-3,5,3,6,7};
	int k = 3;

	debug(s.maxSlidingWindow(nums, k));

	nums = {1};
	k = 1;

	debug(s.maxSlidingWindow(nums, k));

	nums = {-7,-8,7,5,7,1,6,0};
	k = 4;

	debug(s.maxSlidingWindow(nums, k));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T
	while(T--){
		solve();
	}
	return 0;
}
