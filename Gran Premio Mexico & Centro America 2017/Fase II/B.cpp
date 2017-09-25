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

using namespace std;

int main(){
    int n, b, sum, num;

    while(scanf("%d %d",&n,&b) && (n != 0 && b != 0)){
        sum = 0;
        for(int i = 0; i < n; i++)
            scanf("%d",&num), sum += num;
        printf("%d\n",(b/sum));
    }
    return 0;
}
