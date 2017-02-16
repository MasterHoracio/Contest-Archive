#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 200

int main(){
	int n, xa, ya, xb, yb, xc, yc;
	long double a, b, c, p, area, max = -1000000;
	char str[MAX], maxstr[MAX];

	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%s %d %d %d %d %d %d",str,&xa,&ya,&xb,&yb,&xc,&yc);

		a = sqrt(pow(((long double)xb - (long double)xa),2) + pow(((long double)yb - (long double)ya),2));
		b = sqrt(pow(((long double)xc - (long double)xb),2) + pow(((long double)yc - (long double)yb),2));
		c = sqrt(pow(((long double)xa - (long double)xc),2) + pow(((long double)ya - (long double)yc),2));

		p = (a + b + c) / 2;

		area = sqrt(p * (p - a) * (p - b) * (p - c));


		if(area > max){
			max = area;
			strcpy(maxstr,str);
		}
	}

	printf("%s %.2Lf km^2\n",maxstr,max);
}