#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	int len, vowel[5];

	vowel[0] = vowel[1] = vowel[2] = vowel[3] = vowel[4] = 0;

	getline(cin,str);

	do{
		len = str.length();
		for(int i = 0; i < len; i++){
			if(str[i] == 'a' || str[i] == 'A')
				vowel[0]++;
			else if(str[i] == 'e' || str[i] == 'E')
				vowel[1]++;
			else if(str[i] == 'i' || str[i] == 'I')
				vowel[2]++;
			else if(str[i] == 'o' || str[i] == 'O')
				vowel[3]++;
			else if(str[i] == 'u' || str[i] == 'U')
				vowel[4]++;
		}
	}while(getline(cin,str));

	cout << vowel[0] << " " << vowel[1] << " " << vowel[2] << " " << vowel[3] << " " << vowel[4] << endl;

	return 0;
}