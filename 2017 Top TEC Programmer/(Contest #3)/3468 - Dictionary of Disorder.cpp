#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map <string, int> mapa;
	string str;
	int n;

	cin >> n;

	while(n--){
		cin >> str;
		sort(str.begin(),str.end());
		if(!mapa[str]){
			cout << "0" << '\n';
			mapa[str] = 1;
		}else{
			cout << mapa[str] << '\n';
			mapa[str] += 1;
		}
	}
	
	return 0;
}