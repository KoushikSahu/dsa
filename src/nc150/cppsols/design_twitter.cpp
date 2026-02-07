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
Created: 03:52:26 PM(15:52:26) IST(+05:30) 07-02-2026 Sat
 */

struct Post {
	int tweet_id, timestamp;

	Post(int tweet_id, int timestamp) : tweet_id(tweet_id), timestamp(timestamp) {}
};

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
		user_posts[userId].push_back(Post(tweetId, ++timestamp));
    }
    
    vector<int> getNewsFeed(int userId) {
		vector<int> user_ids;
		user_ids.push_back(userId);
		for (int i: following[userId]) {
			user_ids.push_back(i);
		}
		vector<int> ptrs(user_ids.size(), 0);
		for (int i = 0; i < user_ids.size(); i++) {
			ptrs[i] = user_posts[user_ids[i]].size() - 1;
		}
		vector<int> ans;
		while (ans.size() < 10) {
			int max_idx = -1, curr_max = -1;
			for (int i = 0; i < user_ids.size(); i++) {
				if (ptrs[i] >= 0 && user_posts[user_ids[i]][ptrs[i]].timestamp > curr_max) {
					curr_max = user_posts[user_ids[i]][ptrs[i]].timestamp;
					max_idx = i;
				}
			}
			if (max_idx == -1) {
				break;
			}
			ans.push_back(user_posts[user_ids[max_idx]][ptrs[max_idx]].tweet_id);
			ptrs[max_idx] -= 1;
		}
		return ans;
    }
    
    void follow(int followerId, int followeeId) {
		following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
		following[followerId].erase(followeeId);
    }

private:
	unordered_map<int, unordered_set<int>> following;
	unordered_map<int, vector<Post>> user_posts;
	int timestamp = -1;
};

void solve(){
	
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
