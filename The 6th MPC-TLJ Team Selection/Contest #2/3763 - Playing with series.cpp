#include <cstdio>
#include <cstring>

#define maxn 1005
#define mod 1000000007

using namespace std;

typedef long long int lld;

int memo[maxn];

lld solve(lld n){
	if(n == 0)
		return 3;
	if(n == 1)
		return 11;
	if(memo[n] != -1)
		return memo[n];

	memo[n] = ((2*solve(n - 1))%mod + (3 * solve(n - 2))%mod)%mod;

	return memo[n];
}

int main(){
	int tc;
	lld n;
	memset(memo, -1, sizeof(memo));
	memo[0] = 3;
	memo[1] = 11;

	scanf("%d",&tc);

	while(tc--){
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
}