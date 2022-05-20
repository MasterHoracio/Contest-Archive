#include <cstdio>

using namespace std;

int main(){
	int n, temp, count = 0, digit;

	scanf("%d",&n);

	temp = n;

	do{
		digit = temp % 10;
		temp /= 10;
		if(digit != 0 && n % digit == 0)
			++count;
	}while(temp > 0);

	printf("%d\n",count);

	return 0;
}