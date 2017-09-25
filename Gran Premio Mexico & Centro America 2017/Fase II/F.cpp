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

#define maxn 1010

using namespace std;

typedef long long int lld;

int main(){
    int tc, f, dp[maxn], len, _max, res, pos;
    map <char, char> acomoda;
    map <char, char>::iterator it;
    char _string[maxn];

    scanf("%d",&tc);

    while(tc--){
        scanf("%s %d",_string,&f);
        len = strlen(_string);
        fill(dp, dp + len, 1);

        for(int i = 97; i <= 122; i++){
            if(i + f <= 122){
                acomoda[i] = i + f;
            }else{
                res = i + f - 122;
                acomoda[i] = 96 + res;
            }
        }

        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                if(acomoda[_string[j]] <= _string[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        _max = -1;
        for(int i = 0; i < len; i++)
            if(dp[i] > _max)
                _max = dp[i];

        printf("%d\n",_max);
        acomoda.clear();
    }
    return 0;
}
