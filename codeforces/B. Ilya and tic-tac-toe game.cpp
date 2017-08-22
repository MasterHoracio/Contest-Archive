#include <cstdio>

using namespace std;

int radius[2][4] = {{-1, -1, 0, 1},{0, 1, 1, 1}};
int middle[2][8] = {{-1, -1, 0, 1, 1, 1, 0, -1},{0, 1, 1, 1, 0, -1, -1, -1}};
int multiple[2][8] = {{-2, -2, 0, 2, 2, 2, 0, -2},{0, 2, 2, 2, 0, -2, -2, -2}};

bool isPosibleToWin(char board[4][4], int i, int j){
	//check the radius
	for(int k = 0; k < 4; k++){
		if( (i + radius[0][k] >= 0 && i + radius[0][k] < 4) && (i + (radius[0][k] * -1) >= 0 && i + (radius[0][k] * -1) < 4 ) ){
			if( (j + radius[1][k] >= 0 && j + radius[1][k] < 4) && (j + (radius[1][k] * -1) >= 0 && j + (radius[1][k] * -1) < 4 ) ){
				if(board[i + radius[0][k]][j + radius[1][k]] == 'x' && board[i + (radius[0][k] * -1)][j + (radius[1][k] * -1)] == 'x')
					return true;
			}
		}
	}
	//check multiple
	for(int k = 0; k < 8; k++){
		if(i + multiple[0][k] >= 0 && i + multiple[0][k] < 4){
			if(j + multiple[1][k] >= 0 && j + multiple[1][k] < 4){
				if(board[i + multiple[0][k]][j + multiple[1][k]] == 'x' && board[i + middle[0][k]][j + middle[1][k]] == 'x')
					return true;
			}
		}
	}
	
	return false;
}

int main(){
	char board[4][4];
	bool check;
	
	for(int i = 0; i < 4; i++)
		scanf("%s",board[i]);
		
	check = false;
		
	for(int i = 0; i < 4 && !check; i++){
		for(int j = 0; j < 4 && !check; j++){
			if(board[i][j] == '.'){
				check = isPosibleToWin(board, i, j);
			}
		}
	}
	
	(check) ? printf("YES\n") : printf("NO\n");
	
	return 0;
}
