#include <bits/stdc++.h>
using namespace std;
int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		map<string, int> mp;
		int n;
		cin >> n;
		for(int i = 0; i < 3*n; i++) {
			string ss;
			int temp;
			cin >> ss >> temp;
			mp[ss] += temp;
		}
		vector<int> ans;
		for(auto i : mp) {
			ans.emplace_back(i.second);
		}
		sort(ans.begin(), ans.end());
		for(auto i : ans)
			cout << i << " ";
		cout << '\n';
	}
}