#include <stdio.h>

int main(){
	int a, b, tc;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&a,&b);
		printf("%.2f\n",(float)a/(float)b);
	}
}