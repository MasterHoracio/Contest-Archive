#include <iostream>
#include <cmath>

using namespace std;

int main(){
    unsigned long long int n, tmp, ans;

    while(cin >> n && n != 0){
        ans = n;
        do{
            tmp = ans;
            ans = 0;
            while(tmp){
                ans += tmp % 10;
                tmp /= 10;
            }
        }while(ans >= 10);
        cout << ans << endl;
    }
    return 0;
}
