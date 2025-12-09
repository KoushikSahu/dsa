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
	Created: 12:48:29 AM(00:48:29) IST(+05:30) 10-12-2025 Wed
*/

class Solution {
public:
	vector<vector<int>> permute_recursive(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> curr;
		permute_recursive(curr, ans, nums);
		return ans;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		do{
			ans.push_back(nums);
		}while(next_permutation(nums));
		return ans;
	}

private:
	void permute_recursive(vector<int> curr, vector<vector<int>>& ans, vector<int> nums) {
		int n = (int)nums.size();
		if(nums.empty()){
			ans.push_back(curr);
		}
		for(int i=0; i<n; i++) {
			curr.push_back(nums[i]);
			vector<int> nums_tmp = nums;
			nums_tmp.erase(nums.begin() + i);
			permute_recursive(curr, ans, nums_tmp);
			curr.pop_back();
		}
	}

	bool next_permutation(vector<int>& a){
		int n = (int)a.size();
		int pivot = -1;
		for(int i=n-2; i>=0; i--){
			if(a[i] < a[i+1]) {
				pivot = i;
				break;
			}
		}
		if(pivot == -1){
			return false;
		}
		int nextGreater = -1;
		for(int i=pivot; i<n; i++) {
			if(a[i] > a[pivot]) {
				nextGreater = i;
			}
		}
		swap(a[pivot], a[nextGreater]);
		reverse(a.begin() + pivot + 1, a.end());
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		vector<int> a{1, 2, 3};
		auto ans = s.permute(a);
		for(auto v: ans){
			for(auto i: v){
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
