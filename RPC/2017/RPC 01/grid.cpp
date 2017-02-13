#include <cstdio>
#include <queue>

#define MAX 505
#define DEF 99999999

using namespace std;

typedef struct{
	int renglon;
	int columna;
	int valor;
	int saltos;
}position;

int min(int a, int b){if(a < b) return a; else return b;}

int solve(int grid[MAX][MAX], bool visited[MAX][MAX], int n, int m){
	queue <position> Queue;
	position temp, aux;
	int min = DEF, val;

	temp.valor = grid[0][0];
	temp.renglon = 0;
	temp.columna = 0;
	temp.saltos = 0;
	visited[0][0] = true;

	Queue.push(temp);

	while(!Queue.empty()){
		temp = Queue.front();
		Queue.pop();

		if(temp.renglon == n - 1 && temp.columna == m - 1){//valida llegar al final
			if(min > temp.saltos)
				min = temp.saltos;
		}

		val = temp.valor;

		//checamos en puntos cardinales
		if(temp.renglon - val >= 0 && visited[temp.renglon - val][temp.columna] == false){
			aux.renglon = temp.renglon - val;
			aux.columna = temp.columna;
			aux.valor = grid[temp.renglon - val][temp.columna];
			aux.saltos = temp.saltos + 1;
			visited[temp.renglon - val][temp.columna] = true;
			Queue.push(aux);
		}if(temp.renglon + val < n && visited[temp.renglon + val][temp.columna] == false){
			aux.renglon = temp.renglon + val;
			aux.columna = temp.columna;
			aux.valor = grid[temp.renglon + val][temp.columna];
			aux.saltos = temp.saltos + 1;
			visited[temp.renglon + val][temp.columna] = true;
			Queue.push(aux);
		}if(temp.columna - val >= 0 && visited[temp.renglon][temp.columna - val] == false){
			aux.renglon = temp.renglon;
			aux.columna = temp.columna - val;
			aux.valor = grid[temp.renglon][temp.columna - val];
			aux.saltos = temp.saltos + 1;
			visited[temp.renglon][temp.columna - val] = true;
			Queue.push(aux);
		}if(temp.columna + val < m && visited[temp.renglon][temp.columna + val] == false){
			aux.renglon = temp.renglon;
			aux.columna = temp.columna + val;
			aux.valor = grid[temp.renglon][temp.columna + val];
			aux.saltos = temp.saltos + 1;
			visited[temp.renglon][temp.columna + val] = true;
			Queue.push(aux);
		}


	}

	return min;
}

int main(){
	int n, m, grid[MAX][MAX], value;
	bool visited[MAX][MAX];
	char cad[MAX];

	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++){
		scanf("%s",cad);
		for(int j = 0; j < m; j++){
			grid[i][j] = cad[j] - '0';
		}
	}

	value = solve(grid, visited, n, m);

	(value == DEF) ? printf("IMPOSSIBLE\n") : printf("%d\n",value);

	return 0;
}