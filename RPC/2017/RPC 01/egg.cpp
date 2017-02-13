#include <iostream>
#include <string>

using namespace std;

int main(){
	bool hasSafe = false, hasBroken = false;
	int n, k, piso, minpiso, maxpiso;
	string str;

	cin >> n >> k;

	minpiso = k;
	maxpiso = 1;

	for(int i = 0; i < n; i++){
		cin >> piso >> str;
		if(str == "SAFE"){
			hasSafe = true;
			if(piso > maxpiso)
				maxpiso = piso;
		}else{
			hasBroken = true;
			if(piso < minpiso)
				minpiso = piso;
		}
	}

	
	if(hasSafe && hasBroken){
		if(maxpiso + 1 == minpiso){
			cout << minpiso << " " << maxpiso << "\n";
		}else{
			maxpiso++;
			minpiso--;
			cout << maxpiso << " " << minpiso << "\n";
		}
	}else if(hasSafe){
		minpiso--;
		maxpiso++;
		cout << maxpiso << " " << minpiso << "\n";
	}else{
		maxpiso++;
		minpiso--;
		cout << maxpiso << " " << minpiso << "\n";
	}


	return 0;
}