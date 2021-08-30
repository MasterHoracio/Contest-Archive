#include <iostream>
#include <string>

using namespace std;

int main(){
	int cases, len, CON, VOC, ascii[256], MAX_CON, MAX_VOC, seconds;
	bool consistent;
	string present;
	
	#freopen("i.txt", "r", stdin);
    #freopen("o.txt", "w", stdout); 
    
	cin >> cases;
	
	for(int i = 0; i < cases; i++){
		cin >> present;
		
		len = present.length();
		fill(ascii, ascii + 256, 0);
		VOC = CON = 0;
		
		for(int j = 0; j < len; j++){
			ascii[present[j]] += 1;
			if(present[j] == 'A' || present[j] == 'E' || present[j] == 'I' || present[j] == 'O' || present[j] == 'U'){
				VOC += 1;
			}else{
				CON += 1;
			}
		}
		
		if(VOC == 0 || CON == 0){
			consistent = true;
			for(int j = 0; j < len -1; j++){
				if(present[j] != present[j + 1]){
					consistent = false;
				}
			}
			if(consistent == true){
				cout << "Case #" << i+1 << ": 0" << endl;
			}else{
				cout << "Case #" << i+1 << ": " << max(VOC, CON) << endl;
			}
		}else{
			MAX_VOC = MAX_CON = 0;
			for(int j = 65; j < 91; j++){
				if(j == 65 || j == 69 || j == 73 || j == 79 || j == 85){
					if(ascii[j] > MAX_VOC){
						MAX_VOC = ascii[j];
					}
				}else{
					if(ascii[j] > MAX_CON){
						MAX_CON = ascii[j];
					}
				}
			}
			seconds = min(CON+((VOC-MAX_VOC)*2),VOC+((CON-MAX_CON)*2));
			cout << "Case #" << i+1 << ": " << seconds << endl;
		}
	}
	
	return 0;
}
