#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int  maxn = 1300010;
typedef unsigned long long int lld;

vector <int> primes;
bool isPrime[maxn];

void sieve(){
    memset(isPrime, 0, sizeof(isPrime));

    for(lld i = 2; i < maxn; i++){
        if(!isPrime[i]){
            primes.push_back(i);
            for(lld j = i * i; j < maxn; j += i)
                isPrime[j] = true;
        }
    }
}

int main(){
    int a, b, lef, rig, _max, curr, mi, ma;

    sieve();

    while(scanf("%d %d",&a,&b) && (a != 0 && a != 0)){
        mi = min(a, b);
        ma = max(a, b);
        lef = lower_bound(primes.begin(), primes.end(), mi) - primes.begin();
        rig = (upper_bound(primes.begin(), primes.end(), ma) - primes.begin()) - 1;
        _max = -999999;
        for(int i = lef; i <= rig; i++){
            if(i + 1 <= rig){
                curr = primes[i + 1] - primes[i];
                if(curr > _max)
                    _max = curr;
            }
        }
        (_max == -999999) ? printf("NULL\n") : printf("%d\n",_max);
        //printf("%d %d\n",lef, rig);
    }

    return 0;
}
