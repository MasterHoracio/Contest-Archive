#include <iostream>

using namespace std;

typedef long long int lld;
const lld _max = 15e7;

lld formula(lld n){
    return (n * (n + 1)) / 2;
}

lld binarySearch(lld n){
    lld lef = 1, rig = _max, mid, res, izq;

    while(lef <= rig){
        mid = (lef + rig) / 2;
        res = formula(mid);
        izq = (res - mid) + 1;
        if(n >= izq && n <= res)
            return mid;
        else if(res < n)
            lef = mid + 1;
        else if(izq > n)
            rig = mid - 1;
    }
    return -1;
}

int main(){
    lld n, capa;

    cin >> n;

    capa = binarySearch(n);

    cout << n - (formula(capa) - capa) << endl;

    return 0;
}