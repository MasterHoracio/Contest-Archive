#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int p, ri;

	scanf("%d",&p);

	while(p--){
		scanf("%d",&ri);
		printf("%.2f\n",((acos(0)*2.0) * pow((float)ri,2)) - (pow((ri * 2),2) / 2) );
	}
	return 0;
}