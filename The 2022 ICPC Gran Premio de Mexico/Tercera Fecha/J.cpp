#include <cstdio>

using namespace std;

int main(){
    int j1, j2, m1, m2, n, ronda, juan, maria, cartas[14], ans, aux;
    bool found = false;

    for(int i = 1; i < 14; i++)
        cartas[i] = 4;

    scanf("%d",&n);

    scanf("%d %d",&j1,&j2);
    cartas[j1] -= 1;
    cartas[j2] -= 1;

    scanf("%d %d",&m1,&m2);
    cartas[m1] -= 1;
    cartas[m2] -= 1;

    if(j1 > 10)
        j1 = 10;
    if(j2 > 10)
        j2 = 10;
    juan = j1 + j2;

    if(m1 > 10)
        m1 = 10;
    if(m2 > 10)
        m2 = 10;
    maria = m1 + m2;

    for(int i = 0; i < n; i++){
        scanf("%d",&ronda);
        cartas[ronda] -= 1;
        if(ronda > 10)
            ronda = 10;
        juan += ronda;
        maria += ronda;
    }

    for(int i = 1; i < 14 && !found; i++){
        if(cartas[i] > 0){
            if(i > 10){
                aux = 10;
            }else{
                aux = i;
            }
            if(maria + aux == 23 || (juan + aux > 23 && maria + aux <= 23)){
                ans = i;
                found = true;
            }
        }
    }

    if(found){
        printf("%d\n",ans);
    }else{
        printf("-1\n");
    }

    return 0;
}