#include <cstdio>
#define MAXN 1000001

using namespace std;

int main(){
    int n, alturas[MAXN] = {0}, globos[MAXN] = {0}, count = 0;

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        scanf("%d",&alturas[i]);

    for(int i = 0; i < n; i++){
        if(globos[alturas[i]] == 0){
            count += 1;
            if(alturas[i] != 1){
                globos[alturas[i] - 1] += 1;
            }
        }else{
            globos[alturas[i]] -= 1;
            if(alturas[i] != 1){
                globos[alturas[i] - 1] += 1;
            }
        }
    }

    printf("%d\n",count);

    return 0;
}