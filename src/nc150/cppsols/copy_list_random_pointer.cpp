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
Created: 01:03:52 AM(01:03:52) IST(+05:30) 31-12-2025 Wed
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomListMap(Node* head) {
		if (!head) return nullptr;
		Node *root = nullptr, *itr = head;
		map<Node*, Node*> mp;
		while (itr) {
			if (mp.find(itr) == mp.end()) {
				Node* new_node = new Node(itr->val);
				mp[itr] = new_node;
				if (root == nullptr) {
					root = new_node;
				}
			}
			Node* new_node = mp[itr];
			if (itr->next) {
				if (mp.find(itr->next) != mp.end()) {
					new_node->next = mp[itr->next];
				} else {
					new_node->next = new Node(itr->next->val);
					mp[itr->next] = new_node->next;
				}
			}
			if (itr->random) {
				if (mp.find(itr->random) != mp.end()) {
					new_node->random = mp[itr->random];
				} else {
					new_node->random = new Node(itr->random->val);
					mp[itr->random] = new_node->random;
				}
			}
			itr = itr->next;
		}
		return root;
    }

    Node* copyRandomList(Node* head) {
		if (!head) return head;
		Node *itr = head;
		while (itr) {
			Node* copy = new Node(itr->val);
			Node* tmp = itr->next;
			itr->next = copy;
			copy->next = tmp;
			itr = tmp;
		}
		itr = head;
		while (itr) {
			if(itr->random) itr->next->random = itr->random->next;
			itr = itr->next->next;
		}
		Node* ans = nullptr;
        Node* itr1 = head, *itr2 = head->next;
		while (itr1) {
			if (!ans) ans = itr2;
			itr1->next = itr1->next->next;
            if(itr1->next) itr2->next = itr1->next->next;
            itr1 = itr1->next;
            itr2 = itr2->next;
		}
		return ans;
    }
};

void solve(){
	Solution s;
	s.copyRandomList(nullptr);
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
