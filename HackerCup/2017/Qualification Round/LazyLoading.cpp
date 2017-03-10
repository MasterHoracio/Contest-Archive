#include <algorithm>
#include <cstdio>
#include <cmath>
#include <deque>

using namespace std;

void borrar(deque <int> &bag, int n){
	for(int i = 1; i < n; i++)
		bag.pop_front();
}

void insertar(deque <int> &bag, int w, int &ans){
	if(w >= 50)
		ans++;
	else
		bag.push_back(w);
}

int main(){
	//freopen("lazyloading.in","r",stdin);
	//freopen("lazyloading.out","w+",stdout);
	int tc, n, w, ans, top, divtion;
	deque <int> bag;

	scanf("%d",&tc);

	for(int j = 1; j <= tc; j++){
		ans = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",&w);
			insertar(bag,w,ans);
		}

		sort(bag.begin(), bag.end());

		while(!bag.empty()){
			top = bag.back();
			divtion = ceil(50 / (float)top);
			if(divtion > bag.size()){
				bag.clear();
			}else{
				bag.pop_back();
				borrar(bag, divtion);
				ans++;
			}
		}

		(j != tc) ? printf("Case #%d: %d\n",j,ans) : printf("Case #%d: %d",j,ans);

	}

	//fclose(stdin);
	//fclose(stdout);

	return 0;
}