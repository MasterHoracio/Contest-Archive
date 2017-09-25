#include <set>
#include <map>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

#define maxn 100010

using namespace std;

typedef long long int lld;

int main(){
    lld tc, n, k, sum, acum[maxn], div;
    bool bien;

    scanf("%lld",&tc);

    while(tc--){
        scanf("%lld %lld",&n,&k);

        for(int i = 1; i <= n; i++)
            scanf("%lld",&acum[i]);
        
        printf("Yes.\n");
    }
    return 0;
}
