#include <stdio.h>
#include <algorithm>

#define MAX 300005

using namespace std;

typedef long long int lld;

struct surf
{
	lld inicio;
	lld final;
	lld fun;
};

bool operator<(surf a, surf b)
{
	return a.inicio < b.inicio;
}

lld dp[MAX];
lld inicios[MAX];
surf Surfeo[MAX];

lld siguiente(lld indice, lld n)
{
	lld final = Surfeo[indice].final;
	return lower_bound(inicios + indice, inicios + n, final) - inicios;
}

int main()
{
	lld n;

	scanf("%lld", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld %lld %lld",&Surfeo[i].inicio ,&Surfeo[i].fun ,&Surfeo[i].final);
		Surfeo[i].final += Surfeo[i].inicio;
	}
			
	sort(Surfeo, Surfeo + n);

	for(int i = 0; i < n; i++)
		inicios[i] = Surfeo[i].inicio;
		
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--)
		dp[i] = max(dp[i + 1], dp[siguiente(i, n)] + Surfeo[i].fun);
		
		printf("%lld\n", dp[0]);

	return 0;
}