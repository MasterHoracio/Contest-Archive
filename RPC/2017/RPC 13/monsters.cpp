#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    int n, monsters[maxn], ans, tmp, positions[maxn];

    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> monsters[i];
            positions[monsters[i]] = i;
        }
        ans = 0;
        for(int i = 1; i <= n; i++){
            if(monsters[i] != i){
                tmp = monsters[i];
                monsters[i] = monsters[positions[i]];
                monsters[positions[i]] = tmp;
                positions[tmp] = positions[i];
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}