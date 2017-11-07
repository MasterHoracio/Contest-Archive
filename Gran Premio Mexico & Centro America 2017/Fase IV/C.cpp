#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 150;

int dp[maxn][maxn];
typedef long long int lld;

/*
int coeficienteBinomial(int n, int k){

    if(dp[n][k] != 0)
        return dp[n][k];

    if (k == 0 || k == n)
        return 1;

    dp[n][k] = coeficienteBinomial(n-1, k-1) + coeficienteBinomial(n-1, k);

    return dp[n][k];
}*/

lld binomialCoeff(lld n, lld k)
{
    lld C[n+1][k+1];
    lld i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}


string convert(lld number){
    string result;

    stringstream convert;
    convert << number;

    result = convert.str();

    return result;
}

int main(){
    lld tc, n, coef, x, y;
    string ans;

    memset(dp, 0, sizeof(dp));

    cin >> tc;

    while(tc--){
        cin >> n;
        ans = "";
        x = n;
        y = 0;
        for(int i = 0; i <= n; i++){
            coef = binomialCoeff(n, i);
            if(coef >= 2){
                ans += convert(coef);
            }
            if(x >= 1){
                if(x == 1){
                    ans += "x";
                }else{
                    ans += "x^";
                    ans += convert(x);
                }
            }
            if(y >= 1){
                if(y == 1){
                    ans += "y";
                }else{
                    ans += "y^";
                    ans += convert(y);
                }
            }

            if(x == 0 && y == 0 && coef == 1)
                ans += "1";
            y++;
            x--;
            if(i + 1 <= n)
                ans += "+";
        }
        cout << ans << endl;
    }
    return 0;
}
