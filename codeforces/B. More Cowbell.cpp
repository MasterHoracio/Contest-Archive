#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 10;

int main(){
	int n, k, arr[maxn], box[maxn], tmpk, max;
	bool lap;
	
	scanf("%d %d",&n,&k);
	
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
		
	memset(box, 0, sizeof(box));
	tmpk = k - 1;
	lap = false;
	
	for(int i = n - 1; i >= 0; i--){
		if(tmpk >= 0 && !lap){
			box[tmpk--] = arr[i];
		}else{
			box[++tmpk] += arr[i];
			lap = true;
		}
	}
	
	max = -999;
	
	for(int i = 0; i < k; i++)
		if(max < box[i])
			max = box[i];
	
	printf("%d\n",max);
	
	return 0;
}
