#include <cstdio>

using namespace std;

int main(){
    bool ans = true;
    int bit;

    for(int i = 0; i < 8; i++){
        scanf("%d",&bit);
        if(bit == 9)
            ans = false;
    }

    if(ans){
        printf("S\n");
    }else{
        printf("F\n");
    }

    return 0;
}