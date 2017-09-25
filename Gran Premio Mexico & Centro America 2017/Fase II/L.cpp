#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define PRIME_LIMIT 31622

using namespace std;

typedef long long int lld;

vector <lld> primes;

void sieve(){
	lld is_prime[PRIME_LIMIT + 1];
	fill(is_prime, is_prime + PRIME_LIMIT + 1, 1);
	for(int i = 2; i <= PRIME_LIMIT; i++){
		if(is_prime[i] == 1){
			primes.push_back(i);
			for(int j = i * i; j <= PRIME_LIMIT; j += i){
				is_prime[j] = 0;
			}
		}
	}
}

lld euler_totient(lld n){
	double result = n;
	lld curr_prime;
	int indx = 0;
	curr_prime = primes[indx];
	while(curr_prime * curr_prime <= n){
		if(n % curr_prime == 0){
			while(n % curr_prime == 0)
				n /= curr_prime;
			result *= (1.0 - (1.0 / (double)curr_prime));
		}
		++indx;
		curr_prime = primes[indx];
	}
	if(n > 1)
		result *= (1.0 - (1.0 / (double)n));
	return (lld)result;
}

int main(){
	lld n, ans;
	int tc;
	
	sieve();
	
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%lld",&n);
		ans = euler_totient(n);
		printf("%lld %.4lf\n",ans,(double)ans/2.0 );
	}
	return 0;
}
