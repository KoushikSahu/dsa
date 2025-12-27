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
	Created: 01:18:13 AM(01:18:13) IST(+05:30) 27-12-2025 Sat
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
		queue<TreeNode *> q;
		q.push(root);
		q.push(nullptr);
		vector<int> tmp;
		while (!q.empty())
		{
			TreeNode *node = q.front();
			q.pop();
			if (node == nullptr) {
				if (!tmp.empty()) {
					ans.push_back(tmp);
					tmp.clear();
					q.push(nullptr);
					continue;
				} else {
					break;
				}
			}
			tmp.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
		}
        if (!tmp.empty()) ans.push_back(tmp);
		return ans;
	}
};

/*
* Useful for leetcode style tree input
*/
TreeNode* constructTree(const string& str) {
	if (str.empty() || str == "[]") return nullptr;
	string s = str.substr(1, str.size() - 2);
	stringstream ss(s);
	string item;
	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop();
		if (getline(ss, item, ',')) {
			if (item != "null") {
				TreeNode* leftChild = new TreeNode(stoi(item));
				node->left = leftChild;
				q.push(leftChild);
			}
		}
		if (getline(ss, item, ',')) {
			if (item != "null") {
				TreeNode* rightChild = new TreeNode(stoi(item));
				node->right = rightChild;
				q.push(rightChild);
			}
		}
	}
	return root;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		string tree = "[3,9,20,null,null,15,7]";
		TreeNode* root = constructTree(tree);
		debug(s.levelOrder(root));
	}
	return 0;
}
