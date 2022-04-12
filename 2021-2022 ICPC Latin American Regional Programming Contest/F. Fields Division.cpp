#include <bits/stdc++.h>
#define MAXN 300001

using namespace std;

//OBS: 2^n > 2^(n-1) + 2^(n-2) + ... + 2^2 + 2^1

vector <int> G[MAXN];
char ans[MAXN];

void DFS(int node, int n){
	queue <int> Q;
	int current;
	
	Q.push(node);
	
	while(!Q.empty()){
		current = Q.front();
		ans[current] = 'B';
		Q.pop();
		for(int i = 0; i < G[current].size(); i++){
			if(G[current][i] != n && ans[G[current][i]] == 'A'){
				Q.push(G[current][i]);
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n, m, u, v;
	memset(ans, 'A', MAXN);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	DFS(n-1, n);
	
	for(int i = 1; i <= n; i++)
		(i < n) ? cout << ans[i] : cout << ans[i] << endl;
	
	return 0;
}
