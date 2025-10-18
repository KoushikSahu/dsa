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
	Created: 08:17:39 AM(08:17:39) IST(+05:30) 16-10-2025 Thu
*/

class Solution {
public:
	// time complexity: O(n^2 log n)
	vector<vector<int>> threeSumSlow(vector<int>& nums) {
		int n = (int)nums.size();
		set<int> seen;
		set<vector<int>> ans_set;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				int rem = - (nums[i] + nums[j]);
				if(seen.find(rem) != seen.end()){
					vector<int> a{nums[i], nums[j], rem};
					sort(a.begin(), a.end());
					ans_set.insert(a);
				}
			}
			seen.insert(nums[i]);
		}
		vector<vector<int>> ans;
		for(auto itr=ans_set.begin(); itr!=ans_set.end(); itr++){
			vector<int> a = *itr;
			ans.push_back(a);
		}
		return ans;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = (int)nums.size();
		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());

		for(int i=0; i<n; i++) {
			if(i>0 && nums[i] == nums[i-1]){
				continue;
			}
			int j = i + 1, k = n-1;
			while(j<k){
				int sm = nums[i] + nums[j] + nums[k];
				if(sm > 0) {
					k--;
				} else if(sm < 0) {
					j++;
				} else {
					ans.push_back({nums[i], nums[j], nums[k]});
					j++;
					while(j<k && nums[j] == nums[j-1]) j++;
				}
			}
		}

		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> a{1, 3, 5, 5,-8, -4, -8};
	auto ans = s.threeSum(a);
	for(auto i: ans){
		for(auto j: i){
			cout<<j<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
