#include <cstdio>
#include <cstring>

#define maxn 100000
#define ascii 256

using namespace std;

int main(){
	int len, value[ascii], val = 1;
	long long int ans = 0;
	char string[maxn];

	for(int i = 'a'; i <= 'z'; i++)
		value[i] = val++;

	scanf("%s",string);

	len = strlen(string);

	for(int i = 0; i < len; i++){
		if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
			ans += 0;
		else
			ans += value[string[i]];
	}

	printf("%lld\n",ans);

	return 0;
}