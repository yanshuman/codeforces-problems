#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
char arr[N][N];
int rooms = 0, n, m;
vector<vector<bool>> visited;
vector<pair<int,int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isValid(int a, int b) {
	if(a < 0 or a >= n or b < 0 or b >= m)
		return false;
	if(visited[a][b])
		return false;
	return true;
}
void dfs(int x, int y) {
	visited[x][y] = true;
	for(auto i : moves) {
		if(isValid(x+i.first, y+i.second)) {
			dfs(x+i.first, y+i.second);
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		vector<bool> temp;
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == '#')
				temp.push_back(true);
			else temp.push_back(false);
		}
		visited.push_back(temp);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visited[i][j]) {
				dfs(i,j), rooms++;
			}
		}
	}
	cout << rooms;
}