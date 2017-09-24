#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

typedef pair <int, int> pii;
typedef struct{
	int left, height;
}facility;

int* computeLeftMax(facility facilities[], int sz){
	stack <pii> svg;
	pii temp;
	
	int *left = new int[sz];
	
	for(int i = 0; i < sz; i++){
		while(!svg.empty() && svg.top().second <= facilities[i].height){
			svg.pop();
		}
		if(svg.empty()){
			left[i] = 0;
		}else{
			left[i] = svg.top().first;
		}
		
		temp.first = i;
		temp.second = facilities[i].height;
		svg.push(temp);
		
	}
	
	return left;
	
}

int* computeRightMax(facility facilities[], int sz){
	stack <pii> svg;
	pii temp;
	
	int *right = new int[sz];
	
	for(int i = sz - 1; i >= 0; i--){
		while(!svg.empty() && svg.top().second <= facilities[i].height){
			svg.pop();
		}
		if(svg.empty()){
			right[i] = 0;
		}else{
			right[i] = svg.top().first;
		}
		
		temp.first = i;
		temp.second = facilities[i].height;
		svg.push(temp);
		
	}
	
	return right;
	
}


int main(){
	int n, x, h, *left, *right, alt, bas;
	double hip_one, hip_two;
	
	scanf("%d",&n);
	
	facility *facilities = new facility[n + 2];
	
	for(int i = 0; i < n + 2; i++)
		scanf("%d %d",&facilities[i].left,&facilities[i].height);
	
	left = computeLeftMax(facilities, n + 2);
	right = computeRightMax(facilities, n + 2);
	
	for(int i = 1; i < n + 1; i++){
		bas = facilities[i].left - facilities[left[i]].left;
		alt = facilities[left[i]].height - facilities[i].height;
		hip_one = sqrt(pow((double)bas, 2) + pow((double)alt, 2));
		bas = facilities[right[i]].left - facilities[i].left;
		alt = facilities[right[i]].height - facilities[i].height;
		hip_two = sqrt(pow((double)bas, 2) + pow((double)alt, 2));
		printf("%d %d %.4lf %.4lf\n",left[i],right[i],hip_one,hip_two);
	}
	
	
	return 0;
}
