#include <bits/stdc++.h>

using namespace std;

int clockwise(int a, int b){
    if(b > a){
        return b - a;
    }else{
        return (360 - a) + b;
    }
}

int nonclockwise(int a, int b){
    if(b < a){
        return a - b;
    }else{
        return a + (360 - b);
    }
}

int main(){
    int n1, n2, d1, d2;
    scanf("%d %d",&n1,&n2);
    if(n1 == n2){
        printf("0\n");
    }else{
        d1 = clockwise(n1, n2);
        d2 = nonclockwise(n1, n2);
        if(d1 <= d2){
            printf("%d\n",d1);
        }else{
            printf("-%d\n",d2);
        }
    }
    return 0;
}