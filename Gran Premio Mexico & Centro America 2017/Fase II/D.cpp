#include <iostream>
#include <algorithm>
#include <vector>

#define INF 3000000000

using namespace std;

typedef long long ll;

vector <ll> truncable[10];
vector <ll> diosPrimes;
ll pot[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

bool isPrime(ll number){
	ll i = 5;
	if(number <= 1){
		return false;
	}else if(number <= 3){
		return true;
	}else if(number % 2 == 0 || number % 3 == 0){
		return false;
	}else{
		while(i * i <= number){
			if(number % i == 0 || number % (i + 2) == 0){
				return false;
			}
			i += 6;
		}
		return true;
	}
}

void buildLeftTruncable(){
	ll base, number;
	base = 10;
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			for(int k = 0; k < truncable[i - 1].size(); k++){
				number = base * j;
				number += truncable[i - 1][k];
				if(isPrime(number)){
					truncable[i].push_back(number);
				}
			}
		}
		base *= 10;
	}
}

bool isLeftTruncable(ll number, ll potencia){
	while(number > 0){
		if(!isPrime(number)){
			return false;
		}
		number = number % pot[potencia--];
	}
	return true;
}

ll _reverse(ll number, ll potencia){
	ll temp = 0;
	while(number > 0){
		temp += pot[potencia--] * (number % 10);
		number /= 10;
	}
	return temp;
}

void buildDiosPrimes(){
	ll number;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < truncable[i].size(); j++){
			ll number = _reverse(truncable[i][j], i);
			if(isLeftTruncable(number, i)){
				diosPrimes.push_back(number);
			}
		}
	}
}


int main(){
	ll tc, a, b, up, low;
	
	truncable[0].push_back(2);
	truncable[0].push_back(3);
	truncable[0].push_back(5);
	truncable[0].push_back(7);
	
	buildLeftTruncable();
	buildDiosPrimes();
	diosPrimes.push_back(INF);
	
	sort(diosPrimes.begin(), diosPrimes.end());
	
	cin >> tc;
	
	while(tc--){
		cin >> a >> b;
		up = upper_bound(diosPrimes.begin(),diosPrimes.end(),b) - diosPrimes.begin();
		low = upper_bound(diosPrimes.begin(),diosPrimes.end(),a - 1) - diosPrimes.begin();
		cout << up - low << endl;
	}
	
	return 0;
}
