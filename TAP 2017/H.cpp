#include <iostream>

using namespace std;

const int maxn = 1e5 + 10;

int main(){
	int n, picture[maxn], ans, pos;
	bool up;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> picture[i];
		
	pos = ans = 0;
	up = false;
	
	for(int i = 0; i < n; i++){
		if(i == 0){
			if(picture[i] > 0){
				++ans;
				up = true;
			}else{
				for(int j = i + 1; j < n && !pos; j++){
					if(picture[j] != 0){
						pos = j;
					}
				}
				if(pos == 0){
					i = n;
				}else{
					i = pos - 1;
				}
			}
		}else{
			if(up == true && picture[i] < picture[i - 1]){
				up = false;
			}else if(up == false && picture[i] > picture[i - 1]){
				up = true;
				++ans;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
