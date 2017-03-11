#include <cstdio>
#include <queue>
#include <cmath>

#define PI 3.14159265359
#define maxn 100005

using namespace std;

double formula(int a, int b, int n){
	return ( ((double)a * (double)b) * sin( ((360 / (double)n) * PI) / 180)) / 2;
}

int main(){
	int n, activitiesSort[maxn], inf, sup, act;
	priority_queue <int> activities;
	double ans;
	bool sw;

	scanf("%d",&n);

	inf = 0; sup = n - 1;

	for(int i = 0; i < n; i++){
		scanf("%d",&act);
		activities.push(act);
	}

	sw = true;

	while(!activities.empty()){
		if(sw){
			activitiesSort[sup--] = activities.top();
			sw = false;
		}else{
			activitiesSort[inf++] = activities.top();
			sw = true;
		}
		activities.pop();
	}

	ans = 0.0;
	
	for(int i = 0; i < n; i++)
		ans += (i + 1 < n) ? formula(activitiesSort[i], activitiesSort[i + 1], n) : formula(activitiesSort[i], activitiesSort[0], n);
	

	printf("%.3lf\n",ans);

	return 0;
}