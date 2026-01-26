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
Created: 11:13:10 AM(11:13:10) IST(+05:30) 26-01-2026 Mon
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		if (!root) return "null";
		string ans = "";
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (!ans.empty()) {
				ans += '|';
			}
			if (t == nullptr) ans += "null";
			else {
				ans += to_string(t->val);
			}
			if (t != nullptr) {
				q.push(t->left);
				q.push(t->right);
			}
		}
		return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		vector<string> vals;
		string curr = "";
		for (const char& c: data) {
			if (c == '|') {
				vals.push_back(curr);
				curr = "";
				continue;
			}
			curr += c;
		}
		vals.push_back(curr);
		TreeNode* ans = nullptr;
		// construct tree
		bool left_filled = false;
		queue<TreeNode*> q;
		for (const string& val: vals) {
			TreeNode* new_node = nullptr;
			if (val != "null") {
				new_node = new TreeNode(stoi(val));
			}
			if (q.empty()) {
				ans = new_node;
				q.push(new_node);
				continue;
			}
			if (!left_filled && q.front()) {
				q.front()->left = new_node;
				if (new_node) q.push(new_node);
				left_filled = true;
			} else if (left_filled && q.front()) {
				q.front()->right = new_node;
				q.pop();
				if (new_node) q.push(new_node);
				left_filled = false;
			}
		}
		return ans;
    }
};

void solve(){
	Codec c;
	TreeNode* root = c.deserialize("1|2|3|null|null|4|5");
	cout << c.serialize(root) << '\n';
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
