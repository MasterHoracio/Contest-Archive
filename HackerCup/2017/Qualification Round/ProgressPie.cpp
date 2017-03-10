#include <cstdio>
#include <cmath>

#define PI 3.14159265359

using namespace std;

bool isInProgressPie(int x, int y, int p){
	x -= 50;
	y -= 50;
	double angle = atan2(y, x) * 180 / PI;
	double progress = ((double) 360.00 * (double)p) / (double) 100;
	if(angle < 0)
		angle += 360;

	if(sqrt(pow(y, 2) + pow(x, 2)) > 50.00)
		return false;

	if(x >= 0 && y >= 0)
		angle = 90 - angle;
	else if(x >= 0 && y < 0)
		angle = 90 + (360 - angle);
	else if(x < 0 && y < 0)
		angle = 180 + (270 - angle);
	else
		angle = 270 + (180 - angle);

	if(angle > progress)
		return false;

	return true;
}

int main(){
	//freopen("progresspie.in","r",stdin);
	//freopen("progresspie.out","w+",stdout);

	int x, y, p, tc;

	scanf("%d",&tc);

	for(int i = 1; i <= tc; i++){
		scanf("%d %d %d",&p,&x,&y);
		(isInProgressPie(x, y, p) && p != 0) ? printf("Case #%d: black\n",i) : printf("Case #%d: white\n",i);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}