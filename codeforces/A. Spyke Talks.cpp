#include <iostream>
#include <map>

using namespace std;

int main(){
    map <long long int, int> count;
    long long int n, num, ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        if(num != 0 && ans != -1){
            count[num]++;
            if(count[num] == 2)
                ans++;
            else if(count[num] > 2)
                ans = -1;
        }
    }

    cout << ans << endl;

    return 0;
}