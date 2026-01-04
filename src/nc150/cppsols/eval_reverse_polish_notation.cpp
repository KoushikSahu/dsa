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
	Created: 12:42:57 PM(12:42:57) IST(+05:30) 03-01-2026 Sat
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		function<bool(string)> is_operator = [](const string& token) {
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				return true;
			}
			return false;
		};

		function<int(int, int, string)> operate = [](int oprd1, int oprd2, string oprt) {
			if (oprt == "+") {
				return oprd1 + oprd2;
			} else if (oprt == "-") {
				return oprd1 - oprd2;
			} else if (oprt == "*") {
				return oprd1 * oprd2;
			}
			return oprd1 / oprd2;
		};
		
		stack<int> st;
		for (const string& s: tokens) {
			if (is_operator(s)) {
				int oprd2 = st.top();
				st.pop();
				int oprd1 = st.top();
				st.pop();
				st.push(operate(oprd1, oprd2, s));
				continue;
			}
			st.push(stoi(s));
		}
		return st.top();
    }
};

void solve() {
	Solution s;
	vector<string> tokens {"2","1","+","3","*"};
	cout << s.evalRPN(tokens) << '\n';
	tokens = {"4","13","5","/","+"};
	cout << s.evalRPN(tokens) << '\n';
	tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << s.evalRPN(tokens) << '\n';
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
