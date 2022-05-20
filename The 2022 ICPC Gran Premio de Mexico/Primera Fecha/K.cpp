#include <bits/stdc++.h>

int dp[51][55001];

using namespace std;

int main(){
	int k, p, presentations[51], dinner, max_dinner, left, min_left;
	vector <int> dinners;

	scanf("%d %d",&k,&p);

	for(int i = 0; i < p; i++)
		scanf("%d",&presentations[i]);

	sort(presentations, presentations + p);

	max_dinner = -1;

	for(int i = 0; i < k; i++){
		scanf("%d",&dinner);
		max_dinner = max(max_dinner, dinner);
		dinners.push_back(dinner);
	}

	max_dinner += 5000;

	for(int i = 0; i <= p; i++)
		for(int j = 0; j <= max_dinner; j++)
			dp[i][j] = 0;

	for(int i = 1; i <= p; i++){
		for(int j = 1; j <= max_dinner; j++){
			if(j < presentations[i - 1]){
				dp[i][j] = dp[i - 1][j];
			}else{
				dp[i][j] = max(dp[i - 1][j], presentations[i - 1] + dp[i][j - presentations[i - 1]]);
			}
		}
	}

	for(int i = 0; i < k; i++){
		left = dinners[i] - dp[p][dinners[i]];
		if(left == 0){
			printf("%d\n",left);
		}else{
			min_left = abs(left - presentations[0]);
			for(int j = dinners[i]; j <= max_dinner; j++){
				if(dp[p][j] >= dinners[i]){
					min_left = min(min_left, abs(dp[p][j] - dinners[i]));
				}else{
					min_left = min(min_left, abs((dinners[i] - dp[p][j]) - presentations[0]));
				}
			}
			printf("%d\n",min_left);
		}
	}

	return 0;
}