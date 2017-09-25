#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 100;
const ll MOD = 1e9 + 7;

ll primes[MAXN], primeSum[MAXN], pot[MAXN];

void sieveSum(){
	for(ll i = 2; i < MAXN; i++){
		if(!primes[i]){
			for(int j = i; j < MAXN; j += i)
				++primes[j];
		}
	}
	
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int x, y, n;
	ll temp = 2;
	
	sieveSum();
	pot[0] = 1;
	pot[1] = 2;
	
	for(ll i = 2; i < MAXN; i++){
		primeSum[i] = primeSum[i - 1] + primes[i];
		primeSum[i] %= MOD;
		temp *= 2;
		temp %= MOD;
		pot[i] = temp;
	}
	
	while(cin >> n >> x >> y){
		if(n == 0 && x == 0 && y == 0)
			break;
		cout << (primeSum[y - x] * pot[y - x- 1]) % MOD << "\n";
	}
	
	return 0;
}
