#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> lead;

void dfs(int curr) {
	vis[curr] = true;
	for(auto i : adj[curr]) {
		if(!vis[i]) {
			dfs(i);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			lead.push_back(i);
			dfs(i);
		}
	}
	cout << (int)lead.size()-1 << '\n';
	int a = lead[0];
	for(int i = 1; i < (int)lead.size(); i++) {
		int b = lead[i];
		cout << a << " " << b << '\n';
		a = b;
	}
}