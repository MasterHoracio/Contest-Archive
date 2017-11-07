#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int s;
    char c;

    while(~scanf("%d %c",&s,&c)){
        if(s == 1){
            printf("1\n");
        }else{
            if(c == 'K'){
                printf("4\n");
            }else if(c == 'N'){
                (s == 2) ? printf("1\n") : printf("2\n");
            }else{
                printf("%d\n",s);
            }
        }
    }

    return 0;
}