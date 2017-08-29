#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn = 2e3 + 10;

int main(){
    int n, lef, rig, i = 0, mid, indx;
    char s[maxn], str[maxn];

    scanf("%d",&n);
    scanf("%s",s);

    if(n % 2 == 1){
        mid = n / 2;
    }else{
        mid = (n / 2) - 1;
    }

    lef = mid - 1;
    rig = mid + 1;
    str[mid] = s[0];
    indx = n - 1;
    for(i = 1; i < n; i++){
        if(indx % 2 == 0){
            str[lef--] = s[i];
        }else{
            str[rig++] = s[i];
        }
        indx--;
    }

    str[i++] = '\0';

    printf("%s\n",str);

    return 0;
}
