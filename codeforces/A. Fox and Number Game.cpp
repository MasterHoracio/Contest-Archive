#include <cstdio>

using namespace std;

int min(int a, int b){ if(a < b) return a; return b;}
int max(int a, int b){if(a > b) return a; return b;}
const int maxn = 1e2 + 10;

int gcd(int a, int b){
	if(a == 0)
		return b;
	return gcd(b % a, a);
}

int main(){
	int n, arr[maxn], curr;

	scanf("%d",&n);

	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	curr = gcd(min(arr[0],arr[1]), max(arr[0],arr[1]));

	for(int i = 2; i < n; i++)
		curr = gcd(min(curr,arr[i]),max(curr,arr[i]));

	curr *= n;

	printf("%d\n",curr);

	return 0;
}