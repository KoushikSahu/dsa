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
	Created: 09:03:43 AM(09:03:43) IST(+05:30) 28-10-2025 Tue
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int low = 0, high = (int)nums.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[n-1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        // binary search 0..low-1 and low..n-1
        int pivot = low;
        if(pivot > 0) {
            low = 0;
            high = pivot-1;
            while(low < high) {
            int mid = low + (high - low) / 2;
                if(nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if(nums[low] == target) {
                return low;
            }
        }
        low = pivot;
        high = n - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if(nums[low] == target) {
            return low;
        }
        return -1;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<int> a {4,5,6,7,0,1,2};
	s.search(a, 0);
	return 0;
}
