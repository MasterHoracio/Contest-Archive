#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

int main(){
    ll n, cofres[maxn], piratas[maxn], indx, answ = 1, count = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> piratas[i];

    for(int i = 0; i < n; i++)
        cin >> cofres[i];

    sort(piratas, piratas + n);
    sort(cofres, cofres + n);

    indx = n - 1;
    for(int i = n - 1; i >= 0; i--){
        while(indx >= 0 && cofres[indx] >= piratas[i]){
            indx--;
            count++;
        }
        answ = (answ * count) % MOD;
        count--;
    }
    cout << answ << endl;

    return 0;
}