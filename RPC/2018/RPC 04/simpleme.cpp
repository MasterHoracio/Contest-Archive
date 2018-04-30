#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int main(){
    int n, arr[maxn];
    double result;
    while(scanf("%d",&n) && n != 0){
        for(int i = 0; i < n; i++)
            scanf("%d",&arr[i]);
        sort(arr, arr + n);
        if(n % 2 != 0){
            result = (double)arr[n / 2];
        }else{
            result = ((double)arr[n / 2] + (double)arr[(n / 2) - 1])/2.0;
        }
        printf("%.1lf\n",result);
    }
    return 0;
}