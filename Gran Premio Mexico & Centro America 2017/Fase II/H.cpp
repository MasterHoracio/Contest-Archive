#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int lld;

int main(){
	lld n, last, pot, tc;
	bool piv;

	while(scanf("%lld",&n) && (n != 0)){
		last = n;
		pot = 0;
		piv = true;
		while(n != 1){
			if(n % 2 == 0 && piv == true){
				last -= pow(2, pot);
				n /= 2;
			}else if(n % 2 != 0 && piv == true){
				n /= 2;
				n++;
				piv = false;
			}else if(n % 2 == 0 && piv == false){
				n /= 2;
			}else{
				last -= pow(2, pot);
				n /= 2;
				piv = true;
			}
			pot++;
		}
		printf("%lld\n",last);
	}

}
