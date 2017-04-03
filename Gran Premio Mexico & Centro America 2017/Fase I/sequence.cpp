#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long int tc, n;

	cin >> tc;

	while(tc--){
		cin >> n;
		cout << n * (n + 2) << "\n";
	}

	return 0;
}