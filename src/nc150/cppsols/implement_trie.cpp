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
	Created: 07:37:55 PM(19:37:55) IST(+05:30) 11-01-2026 Sun
*/

const int nxm = 26;

struct TrieNode {
	array<TrieNode*, nxm> children;
	bool is_leaf;

	TrieNode() {
		is_leaf = false;
		for (int i = 0; i < nxm; i++) {
			children[i] = nullptr;
		}
	}
};

class Trie {
public:
    Trie() {
		root = new TrieNode();
    }
    
    void insert(string word) {
		TrieNode* itr = root;

		for (const char& c: word) { 
			if (!itr->children[c - 'a']) {
				itr->children[c - 'a'] = new TrieNode();
			}
			itr = itr->children[c - 'a'];
		}
		itr->is_leaf = true;
    }
    
    bool search(string word) {
		TrieNode* itr = root;

		for (const char& c: word) {
			if (!itr->children[c - 'a']) {
				return false;
			}
			itr = itr->children[c - 'a'];
		}

		return itr->is_leaf == true;
    }
    
    bool startsWith(string prefix) {
		TrieNode* itr = root;

		for (const char& c: prefix) {
			if (!itr->children[c - 'a']) {
				return false;
			}
			itr = itr->children[c - 'a'];
		}

		return true;
    }

private:
	TrieNode* root;
};

void solve(){
	Trie t;
	t.insert("apple");
	cout << t.search("apple") << '\n';
	cout << t.search("app") << '\n';
	cout << t.startsWith("app") << '\n';
	t.insert("app");
	cout << t.search("app") << '\n';
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
