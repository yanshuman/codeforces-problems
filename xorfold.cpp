#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int arr[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		int a = n;
		while(a) {
			a /= 2;
			for(int i = 0; i < a; i++) {
				for(int j = 0; j < m; j++) {
					arr[i][j] = arr[i][j] xor arr[n-i][j];
				}
			}
		}
		int b = m;
		while(b) {
			b /= 2;
			for(int j = 0; j < b; j++) {
				arr[0][j] = arr[0][j] xor arr[0][m-j];
			}
		}
		if(arr[a][b] == 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}