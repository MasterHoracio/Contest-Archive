#include <iostream>
#include <string>

using namespace std;

bool cont;

int solve(string config, int len, int sz){
	int count = 0;
	cont = true;
	for(int j = 0; j < len && cont; j++){
		if(config[j] == '-' && j + sz > len){
			cont = false;
		}else if(config[j] == '-'){
			count++;
			for(int k = j; k < j + sz; k++)
				config[k] = (config[k] == '-') ? '+' : '-';
		}
	}
	return count;
}

int main(){
	freopen("A-large-practice.in", "r", stdin);
	freopen("output.txt", "w+", stdout);
	int tc, sz, ans;
	string config;
	bool check;
	
	cin >> tc;
	
	for(int i = 1; i <= tc; i++){
		cin >> config >> sz;
		ans = solve(config, config.length(), sz);
		(cont) ? cout << "Case #" << i << ": " << ans << "\n" : cout << "Case #" << i << ": " << "IMPOSSIBLE\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
