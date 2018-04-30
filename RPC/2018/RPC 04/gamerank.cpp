#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10;

int main(){
    int len, rank = 25, stars = 0, consecutive = 0;
    char str[maxn];

    scanf("%s",str);
    len = strlen(str);
    for(int i = 0; i < len; i++){
        consecutive = (str[i] == 'W') ? consecutive + 1: 0;
        if(str[i] == 'W')
            ++stars;
        if(consecutive >= 3 && rank >= 6)
            ++stars;
        if(str[i] == 'L'){
            if((rank == 20 && stars > 0) || (rank < 20 && rank != 0))
                stars -= 1;
        }
        if(rank <= 25 && rank >= 21){
            if(stars > 2){
                rank -= 1;
                stars -= 2;
            }
        }else if(rank <= 20 && rank >= 16){
            if(stars < 0){
                rank += 1;
                stars = 2;
            }
            if(stars > 3){
                rank -= 1;
                stars -= 3;
            }
        }else if(rank <= 15 && rank >= 11){
            if(stars < 0){
                rank += 1;
                stars = (rank <= 15) ? 3 : 2;
            }
            if(stars > 4){
                rank -= 1;
                stars -= 4;
            }
        }else if(rank <= 10 && rank >= 1){
            if(stars < 0){
                rank += 1;
                stars = (rank <= 10) ? 4 : 3;
            }
            if(stars > 5){
                rank -= 1;
                stars -= 5;
            }
        }else if(rank == 0){
            break;
        }
    }

    (rank == 0) ? printf("Legend\n") : printf("%d\n",rank);
    
    return 0;
}