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
	Created: 08:37:19 AM(08:37:19) IST(+05:30) 08-12-2025 Mon
*/

class Solution {
public:
    string multiply(string num1, string num2) {
		int n1 = num1.length(), n2 = num2.length();
		string ans = "0";
		int cntr = 0;
		while(n2 > 0){
			string tmp = "";
			int borrow = 0;
			for(int i=n1-1; i>=0; i--){
				int d1 = num1[i] - '0';
				int d2 = num2[n2-1] - '0';
				int prd = d1 * d2 + borrow;
				borrow = prd / 10;
				char to_push = (prd % 10) + '0';
				tmp = to_push + tmp;
			}
			if(borrow != 0){
				char to_push = borrow + '0';
				tmp = to_push + tmp;
			}
			for(int i=0; i<cntr; i++){
				tmp += '0';
			}
			n2 -= 1;
			cntr += 1;
			ans = add(ans, tmp);
		}
		reverse(ans.begin(), ans.end());
		while(ans.back() == '0' && ans.length() > 1){
			ans.pop_back();
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }

private:
	string add(string num1, string num2) {
		int borrow = 0;
		int n1 = num1.length(), n2 = num2.length();
		string ans = "";
		while(n1 > 0 && n2 > 0) {
			int d1 = num1[n1-1] - '0';
			int d2 = num2[n2-1] - '0';
			int sm = d1 + d2 + borrow;
			borrow = sm / 10;
			char to_push = '0' + (sm % 10);
			ans = to_push + ans;
			n1 -= 1;
			n2 -= 1;
		}
		while(n1 > 0){
			int d1 = num1[n1-1] - '0';
			int sm = d1 + borrow;
			borrow = sm / 10;
			char to_push = '0' + (sm % 10);
			ans = to_push + ans;
			n1 -= 1;
		}
		while(n2 > 0){
			int d2 = num2[n2-1] - '0';
			int sm = d2 + borrow;
			borrow = sm / 10;
			char to_push = '0' + (sm % 10);
			ans = to_push + ans;
			n2 -= 1;
		}
		if(borrow != 0){
			char to_push = '0' + borrow;
			ans = to_push + ans;
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){
		Solution s;
		string ans = s.multiply("999", "99999");
		cout << ans << '\n';
	}
	return 0;
}
