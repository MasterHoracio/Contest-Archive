#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc, val, res, op;
	string IMEI;

	cin >> tc;

	while(tc--){
		cin >> IMEI;

		val = 0;

		for(int i = 0; i < IMEI.length(); i++){
			if(i % 2 != 0){
				op = (IMEI[i] - '0') * 2;
				if(op <= 9){
					val += op;
				}else{
					val += (op / 10);
					val += op % 10;
				}
			}else{
				val += IMEI[i] - '0';
			}
		}

		res = val % 10;

		(res == 0) ? cout << res << "\n" : cout << 10 - res << "\n"; 

	}
	return 0;
}