#include <cstdio>
#include <cstdlib>
#include <cstring>

#define maxn 100005

using namespace std;

int main(){
	int n, k, r, cameras[maxn], pos, ans, camera, top;

	scanf("%d %d %d",&n,&k,&r);

	memset(cameras, 0, sizeof(cameras));

	for(int i = 0; i < k; i++){
		scanf("%d",&pos);
		cameras[pos] = 1;
	}
	
	camera = ans = 0;

	for(int i = 1; i <= r; i++)
		if(cameras[i] == 1)
			camera++;

	for(int i = 1; i + r - 1 <= n; i++){
		top = i + r - 1;
		while(camera < 2){
			while(cameras[top] == 1)
				top--;
			cameras[top]++;
			camera++;
			ans++;
		}
		camera += cameras[i + r];
		camera -= cameras[i];
	}

	printf("%d\n",ans);

	return 0;
}