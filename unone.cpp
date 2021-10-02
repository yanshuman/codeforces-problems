#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> odd, even;
		for(int i = 0; i < n; i++) {
			int curr;
			cin >> curr;
			if(curr & 1)
				odd.push_back(curr);
			else 
				even.push_back(curr);
		}
		for(auto i : even)
			cout << i << " ";
		for(auto i : odd)
			cout << i << " ";
		cout << '\n';
	}
}