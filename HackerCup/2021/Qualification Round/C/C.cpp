#include <iostream>

#define LIMITS 51

using namespace std;

int main(){
	int T, N, x_col[LIMITS], x_row[LIMITS], o_col[LIMITS], o_row[LIMITS], extra_col, extra_row, min_col, min_row, g_min, steps, negative;
	char board[LIMITS][LIMITS];
	bool possible;
	
	//freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout); 
	
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		fill(x_col, x_col+LIMITS, 0);
		fill(x_row, x_row+LIMITS, 0);
		fill(o_col, o_col+LIMITS, 0);
		fill(o_row, o_row+LIMITS, 0);
		
		scanf("%d",&N);
		getchar();
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				scanf("%c",&board[j][k]);
				if(board[j][k] == 'X'){
					x_row[j] += 1;
					x_col[k] += 1;
				}else if(board[j][k] == 'O'){
					o_row[j] += 1;
					o_col[k] += 1;
				}
			}
			getchar();
		}
		
		possible = false;
		min_col = min_row = LIMITS;
		for(int j = 0; j < N; j++){
			extra_row = N - (o_row[j] + x_row[j]);
			extra_col = N - (o_col[j] + x_col[j]);
			if(x_row[j] + extra_row == N){
				min_row = min(min_row, extra_row);
				possible = true;
			}
			if(x_col[j] + extra_col == N){
				min_col = min(min_col, extra_col);
				possible = true;
			}
		}
		
		if(possible == false){
			printf("Case #%d: Impossible\n",i+1);
		}else{
			g_min = min(min_row,min_col);
			negative = steps = 0;
			for(int j = 0; j < N; j++){
				extra_row = N - (o_row[j] + x_row[j]);
				extra_col = N - (o_col[j] + x_col[j]);
				if(x_row[j] + extra_row == N && extra_row == g_min){
					steps += 1;
				}
				if(x_col[j] + extra_col == N && extra_col == g_min){
					steps += 1;
				}
			}
			if(g_min == 1 && g_min == min_row && g_min == min_col){
				for(int j = 0; j < N; j++){
					extra_row = N - (o_row[j] + x_row[j]);
					if(x_row[j] + extra_row == N && extra_row == g_min){
						for(int k = 0; k < N; k++){
							extra_col = N - (o_col[k] + x_col[k]);
							if(board[j][k] == '.' && x_col[k] + extra_col == N && extra_col == g_min){
								negative += 1;
							}
						}
					}
				}
			}
			printf("Case #%d: %d %d\n",i+1,g_min, steps-negative);
		}
	}
	
	return 0;
}
