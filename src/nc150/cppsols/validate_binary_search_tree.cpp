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
	Created: 12:05:40 AM(00:05:40) IST(+05:30) 27-12-2025 Sat
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeInfo {
	bool is_bst;
	int max_val;
	int min_val;

	TreeInfo(bool is_bst, int max_val, int min_val) : is_bst(is_bst), max_val(max_val), min_val(min_val) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
		TreeInfo ans = iterateTree(root);
		return ans.is_bst;
    }

private:
	TreeInfo iterateTree(TreeNode* root) {
		if (root == nullptr) return TreeInfo(true, INT_MIN, INT_MAX);
		if (root->left == nullptr && root->right == nullptr) return TreeInfo(true, root->val, root->val);
		bool is_bst = true;
		int max_val = root->val;
		int min_val = root->val;
		TreeInfo leftTreeInfo = iterateTree(root->left);
		TreeInfo rightTreeInfo = iterateTree(root->right);
		if (root->left) {
			is_bst &= root->val > leftTreeInfo.max_val && leftTreeInfo.is_bst;
			max_val = max(max_val, leftTreeInfo.max_val);
			min_val = min(min_val, leftTreeInfo.min_val);
		}
		if (root->right) {
			is_bst &= root->val < rightTreeInfo.min_val && rightTreeInfo.is_bst;
			max_val = max(max_val, rightTreeInfo.max_val);
			min_val = min(min_val, rightTreeInfo.min_val);
		}
		return TreeInfo(is_bst, max_val, min_val);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		cout << s.isValidBST(nullptr) << '\n';
	}
	return 0;
}
