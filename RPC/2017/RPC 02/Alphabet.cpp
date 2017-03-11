#include <cstdio>
#include <cstring>

#define ascii 27
#define maxn 55

using namespace std;

void copy(int a[], int b[]){for(int i = 0; i < ascii; i++)   a[i] = b[i];}

int main() {
   int dp[ascii], temp[ascii], index, ans;
   char str[maxn];

   memset(dp, 0, sizeof(dp));
   memset(temp, 0, sizeof(temp));

   scanf("%s",str);

   for(int i = 0; i < strlen(str); i++){
      index = str[i] - 'a' + 1;
      copy(temp, dp);
      for(int j = 0; j < index; j++)
         if(temp[index] < dp[j] + 1)
            temp[index] = dp[j] + 1;
      copy(dp, temp);
   }

   ans = 0;
   for(int i = 0; i < ascii; i++)
      if(ans < dp[i])
         ans = dp[i];

   printf("%d\n",26 - ans);

   return 0;
}
