#include <algorithm>
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
	Created: 01:15:46 PM(13:15:46) IST(+05:30) 15-01-2026 Thu
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		random_device rd;
		mt19937 g(rd());
		shuffle(nums.begin(), nums.end(), g);
		k = nums.size() - k + 1;
		int low = 0, high = (int)nums.size() - 1;
		while (low < high) {
			int partition = partitioning(nums, low, high);
			if (partition > k - 1) {
				high = partition - 1;
			} else if (partition < k - 1) {
				low = partition + 1;
			} else {
				break;
			}
		}
		return nums[k - 1];
    }

    int findKthLargestPriorityQueue(vector<int>& nums, int k) {
		int n = (int)nums.size();

		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; i++) {
			if (pq.size() < k) {
				pq.push(nums[i]);
				continue;
			}
			int tp = pq.top();
			if (nums[i] >= tp) {
				pq.push(nums[i]);
				pq.pop();
			}
		}

		return pq.top();
    }

private:
	int partitioning(vector<int>& nums, int start, int end) {
		int pivot = nums[start];

		int low = start - 1;
		int high = end + 1;
		
		while (low < high) {
			do {
				low += 1;
			} while (low <= end && nums[low] <= pivot);
			do {
				high -= 1;
			} while (high >= start && nums[high] > pivot);
			if (low < high) {
				swap(nums[low], nums[high]);
			}
		}

		swap(nums[start], nums[high]);
		return high;
	}
};

void solve(){
	Solution s;

	vector<int> nums {3,2,1,5,6,4};
	int k = 2;
	cout << s.findKthLargest(nums, k) << '\n';

	nums = {3,2,3,1,2,4,5,5,6};
	k = 4;
	cout << s.findKthLargest(nums, k) << '\n';
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
