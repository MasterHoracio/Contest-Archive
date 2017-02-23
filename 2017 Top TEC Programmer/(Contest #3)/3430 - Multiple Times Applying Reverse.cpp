#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverse(string cad){
	int len = cad.length() - 1, izq = 0, der;
	char aux;
	der = len;
	while(izq <= der){
		aux = cad[izq];
		cad[izq] = cad[der];
		cad[der] = aux;
		izq++;
		der--;
	}
	return cad;
}

int main(){
	string cad, rev, output;
	stack <int> indices;
	int len, ind;

	while(getline(cin, cad)){
		len = cad.length();
		output = "";
		for(int i = 0; i < len; i++){
			if(indices.empty() && (cad[i] != '(' && cad[i] != ')')){
				output += cad[i];
			}
			else if(cad[i] == '('){
				indices.push(i + 1);
			}else if(cad[i] == ')'){
				ind = indices.top();
				indices.pop();
				rev = reverse(cad.substr(ind, i - ind));
				for(int j = 0; j < rev.length(); j++){
					cad[ind++] = rev[j];
				}
				if(indices.empty()){
					for(int j = 0; j < rev.length(); j++)
						if(rev[j] != '(' && rev[j] != ')')
							output += rev[j];
				}
			}
		}
		cout << output << endl;
	}
	return 0;
}