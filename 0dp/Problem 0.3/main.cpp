#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

long long fact(long long a, long long b){
	long long ans = 1;
	for(long long i = a+1; i <= b; i++){
		ans *= i;
		ans %= mod;
	}
	return ans;
}

long long binPow(long long a, long long n){
	int ans = 1;
    while (n != 0) {
        if (n & 1)
        	ans = ans*a%mod;
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return ans;
}

int main() {

	long long n, k;
	cin >> n >> k;
	k = max(k, n-k);
	long long ans = fact(k, n);
	long long divisor = fact (1, n-k);

	ans *= binPow(divisor, mod-2);
	ans %= mod;
	cout << ans << endl;
}

