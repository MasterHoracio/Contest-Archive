#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 105

using namespace std;

typedef struct{
	string name;
	string lastname;
}alumno;

bool compare(alumno a, alumno b) { return a.lastname < b.lastname; }

int main(){
	alumno array[MAX];
	vector <string> repetidos;
	int names, cont, pos, indx = 1;

	cin >> names;

	for(int i = 0; i < names; i++){
		cin >> array[i].name >> array[i].lastname;
	}


	sort(array, array + names, compare);

	for(int i = 0; i < names; i++){
		if(i + 1 < names && array[i].lastname == array[i + 1].lastname){
			cont = 0;
			pos = i;
			while(pos + 1 < names && array[pos].lastname == array[pos + 1].lastname){
				repetidos.push_back(array[pos].name);
				pos++;
				cont++;
			}
			repetidos.push_back(array[pos].name);
			cont++;

			sort(repetidos.begin(), repetidos.end());

			for(int j = 0; j < cont; j++)
				cout << repetidos[j] << " " << array[i].lastname << "\n";
			i = pos;
			repetidos.clear();
		}else{
			cout << array[i].name << " " << array[i].lastname << "\n";
		}
	}

	return 0;
}