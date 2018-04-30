#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
    ll d, arr[380], money = 100, prev, shares;
    scanf("%lld",&d);
    for(int i = 0; i < d; i++)
        scanf("%lld",&arr[i]);
    prev = arr[0];
    for(int i = 1; i < d; i++){
        if(arr[i] > prev){
            shares = money / prev;
            money -= prev * min(shares, (ll)100000);
            money += min(shares, (ll)100000) * arr[i];
        }
        prev = arr[i];
    }
    printf("%lld\n",money);

    return 0;
}