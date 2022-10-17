#include <cstdio>
#define MAXN 100001

using namespace std;

int main(){
    int n, ans = 0, index;
    char letras[MAXN];

    scanf("%d",&n);
    scanf("%s",letras);

    for(int i = 0; i < n; i++){
        index = i;
        if(index + 1 < n && letras[index] == 'a' && letras[index + 1] == 'a')
            ans += 1;
        while(index + 1 < n && letras[index] == 'a' && letras[index + 1] == 'a'){
            ans += 1;
            index += 1;
        }
        i = index;
    }

    printf("%d\n",ans);

    return 0;
}