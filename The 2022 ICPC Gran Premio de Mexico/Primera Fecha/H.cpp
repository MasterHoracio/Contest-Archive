#include <cstdio>

using namespace std;

int main(){
	int n;

	scanf("%d",&n);

	(n % 4 <= 1) ? printf("%d\n",(n/4)*(n/4)) : printf("%d\n",(n/4)*((n/4) + 1));
	
	return 0;
}