#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

const int nxM = 1e6+5;
int n, m, u, v;
vector<int> g[nxM];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool used[n];
	int par[n];
	fill(used, used+n, false);
	fill(par, par+n, -1);
	function<void(int)> bfs = [&](int src){
		queue<int> q;
		used[src] = true;
		par[src] = -1;
		q.push(src);
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			cout<<curr<<" ";
			for(int adj_ver: g[curr]){
				if(!used[adj_ver]){
					par[adj_ver] = curr;
					used[adj_ver] = true;
					q.push(adj_ver);
				}
			}
		}
	};
	function<void(int)> print_path = [&](int dest){
		vector<int> path;
		for(int i=dest; i!=-1; i=par[i]){
			path.push_back(i);
		}
		reverse(all(path));
		cout<<"Path: ";
		for(int i: path) cout<<i<<" ";
		cout<<"\n";
	};
	cout<<"BFS order: ";
	for(int i=0; i<n; i++){
		if(!used[i]){
			bfs(i);
		}
	}
	cout<<"\n";
	cout<<"Parents of the node\n";
	for(int i=0; i<n; i++){
		cout<<i<<": "<<par[i]<<"\n";
	}
	print_path(3);
    return 0;
}

