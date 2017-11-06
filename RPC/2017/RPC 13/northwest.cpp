#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    ll n, x, y, ans;

    while(cin >> n){
        map <ll, ll> nw, ne;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            ne[x - y]++;//calcula # diagonal
            nw[x + y]++;//calcula # diagonal
        }
        ans = 0;
        for(map<ll, ll>::iterator it = ne.begin(); it != ne.end(); it++)
            if(it->second > 1)
                ans += it->second * (it->second - 1); //n * (n - 1) calcula todas las parejas dados los puntos
        for(map<ll, ll>::iterator it = nw.begin(); it != nw.end(); it++)
            if(it->second > 1)
                    ans += it->second * (it->second - 1); //n * (n - 1) calcula todas las parejas dados los puntos
        cout << setprecision(6) << (double)ans/((double)n * (double)n) << endl;
    }
    return 0;
}