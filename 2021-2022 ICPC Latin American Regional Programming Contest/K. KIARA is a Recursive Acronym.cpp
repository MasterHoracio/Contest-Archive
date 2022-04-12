#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n, len, alphabet[26], comp[26];
	bool acronym = false, check;
	vector <string> list;
	string str;
	
	cin >> n;
	
	for(int j = 0; j < 26; j++)
		alphabet[j] = comp[j] = 0;
	
	for(int i = 0; i < n; i++){
		cin >> str;
		list.push_back(str);
		alphabet[str[0] - 65] += 1;
	}
	
	for(int i = 0; i < n && !acronym; i++){
		len = list[i].length();
		check = true;
		for(int j = 0; j < len; j++)
			comp[list[i][j] - 65] += 1;
		for(int j = 0; j < 26; j++){
			if(comp[j] > 0 && alphabet[j] == 0)
				check = false;
			comp[j] = 0;
		}
		if(check)
			acronym = true;
	}
	
	(acronym) ? cout << "Y" << endl : cout << "N" << endl;
	
	return 0;
}
