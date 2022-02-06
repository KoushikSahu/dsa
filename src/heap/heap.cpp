// https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
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
	Created: 06 February 2022 Sun 12:34:12
*/

void heapify(int arr[], int i, int N){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	if(l < N && arr[l] > arr[largest]) largest = l;
	if(r < N && arr[r] > arr[largest]) largest = r;
	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, largest, N);
	}
}

void build(int arr[], int N){
	for(int i=N/2; i>=0; i--){
		heapify(arr, i, N);
	}
}

int query(int arr[], int& N){
	int largest = arr[0];
	swap(arr[0], arr[N-1]);
	N--;
	heapify(arr, 0, N);
	return largest;
}

void heap_sort(int arr[], int n){
	while(n){
		swap(arr[0], arr[n-1]);
		n--;
		heapify(arr, 0, n);
	}
}

void insert_value(int arr[], int& n, int val){
	n++;
	arr[n-1] = val;
	int i = n-1;
	while(i>=0){
		int parent = (i-1) / 2;
		if(arr[parent] < arr[i]) swap(arr[parent], arr[i]);
		else break;
		i = parent;
	}
}

void solve(){
	int n = 8;
	int nxm = 10;
	int arr[nxm];
	arr[0] = 6;
	arr[1] = 2;
	arr[2] = 1;
	arr[3] = 7;
	arr[4] = 6;
	arr[5] = 3;
	arr[6] = 8;
	arr[7] = 0;
	build(arr, n);
	insert_value(arr, n, 10);
	for(int i: arr) cout<<i<<' ';
	cout<<'\n';
	heap_sort(arr, n);
	for(int i: arr) cout<<i<<' ';
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	// cin>>T; 
	while(T--){
		solve();
	}
	return 0;
}
