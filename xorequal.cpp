// author : Anuj Maurya


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long
const int mod = 1e9+7;


long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void anuj(){
	int n;
	cin >> n;

	ll ans = binpow(2,n-1);
	cout << ans <<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		anuj();
	}
	return 0;
}
