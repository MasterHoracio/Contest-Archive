#include <iostream>
#include <string>
#include <map>

using namespace std;

int findNota(string nota, string notas[]){
	for(int i = 0; i < 12; i++){
		if(nota == notas[i])
			return i;
	}
}

int main(){
	string nota, notas[12] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#", "LA", "LA#" , "SI"};
	int s, pos, ans;
	
	cin >> s >> nota;
	
	pos = findNota(nota, notas);
	
	ans = pos - s;
	
	if(ans >= 0){
		cout << notas[ans] << endl;
	}else{
		cout << notas[12 + ans] << endl;
	}
	
	return 0;
}
