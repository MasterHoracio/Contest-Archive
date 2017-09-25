#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

typedef struct{
	int x, y;
}nodo;

nodo graph[maxn];

bool isInRange(nodo a, nodo b){
	if(a.x == b.x || a.y == b.y)
		return false;
		
	if(a.y == b.x || a.x == b.y)
		return false;
		
	if(b.y > a.y && (b.x < a.y && b.x > a.x))
		return true;
		
	if(b.x < a.x && (b.y > a.x && b.y < a.y))
		return true;
		
	return false;
}

bool comp(nodo a, nodo b){
	return a.x < b.x;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int tc, n, m, contador;
	
	cin >> tc;
	
	while(tc--){
		cin >> n >> m;
		contador = 0;
		for(int i = 0; i < m; i++){
			cin >> graph[i].x >> graph[i].y;
		}
		
		sort(graph, graph + m, comp);
		
		/*for(int i = 0; i < m; i++){
			cout << graph[i].x << " " << graph[i].y << endl;
		}*/
		
		for(int i = 0; i < m; i++){
			for(int j = i + 1; j < m; j++){
				if(graph[j].x > graph[i].y){
					break;
				}if(isInRange(graph[j], graph[i])){
					++contador;
				}
			}
		}
		
		cout << contador << endl;
	}
	
	return 0;
}
