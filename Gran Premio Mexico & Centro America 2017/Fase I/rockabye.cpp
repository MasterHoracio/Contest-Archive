#include <cstdio>
#include <queue>

#define maxn 3050

using namespace std;

typedef pair <int, int> pii;

int main(){
	priority_queue < pii, vector <pii>, greater<pii> > min_heap;
	int tc, n, k, freq, frequency[maxn];
	char names[maxn][30];
	pii temp;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&k);
		for(int i = 0; i < n; i++){
			scanf("%s %d",names[i],&freq);
			min_heap.push(make_pair(freq, i));
			frequency[i] = freq;
		}

		for(int i = 0; i < k; i++){
			temp = min_heap.top();
			min_heap.pop();
			printf("%d %s\n",temp.first, names[temp.second]);
			temp.first += frequency[temp.second];
			min_heap.push(temp);
		}

		while(!min_heap.empty())
			min_heap.pop();
	}

	return 0;
}