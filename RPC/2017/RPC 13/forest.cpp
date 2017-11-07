#include <bits/stdc++.h>

#define LEF '/'
#define RIG 92
#define PAL '|'
#define BAJ '_'
#define ORR '^'
#define TEO 'o'

using namespace std;

typedef long long ll;

char ** initBoard(int n){
    char **board;
    board = new char*[n + 2];
    for(int i = 0; i < n + 2; i++){
        board[i] = new char[n + 2];
        fill(board[i], board[i] + (n + 2), '.');
    }
    for(int i = 0; i < n + 2; i++){
        board[0][i] = '*';  board[n + 1][i] = '*';
        board[i][0] = '*';  board[i][n + 1] = '*';
    }
    return board;
}

void writeTreeStumps(char **board, ll x, ll y, ll n){
    int bx = 1 + x, by = n - y; // (0,0)
    if(bx - 1 > 0 && bx - 1 <= n)
        board[by][bx - 1] = BAJ;
    if(bx > 0 && bx <= n)
        board[by][bx] = TEO;
    if(bx + 1 > 0 && bx + 1 <= n)
        board[by][bx + 1] = BAJ;
}

void writeTreeRoot(char **board, ll x, ll y, ll n){
    int bx = 1 + x, by = n - y; // (0,0)
    if(bx - 1 > 0 && bx - 1 <= n)
        board[by][bx - 1] = BAJ;
    if(bx > 0 && bx <= n)
        board[by][bx] = PAL;
    if(bx + 1 > 0 && bx + 1 <= n)
        board[by][bx + 1] = BAJ;
}

void writeTreeTop(char **board, ll x, ll y, ll n, ll s){
    int bx = 1 + x, by = n - y; // (0,0)
    board[by - s - 1][bx] = ORR;
}

void writeTreeTrunk(char **board, ll x, ll y, ll n){
    int bx = 1 + x, by = n - y; // (0,0)
    if(bx - 1 > 0 && bx - 1 <= n)
        board[by][bx - 1] = LEF;
    if(bx > 0 && bx <= n)
        board[by][bx] = PAL;
    if(bx + 1 > 0 && bx + 1 <= n)
        board[by][bx + 1] = RIG;
}

int main(){
    ios_base::sync_with_stdio(false);
    ll n, m, s, x, y;

    while(scanf("%lld %lld",&n,&m) != EOF){
        char **board = initBoard(n);
        for(int i = 0; i < m; i++){
            scanf("%lld %lld %lld",&s,&x,&y);
            if(s == 0){
                if(y < n && x <= n && y >= 0 && x >= -1){//inside the board
                    writeTreeStumps(board, x, y, n);
                }
            }else{
                if(y < n && x <= n && y >= 0 && x >= -1){//inside the board for root
                    writeTreeRoot(board, x, y, n);
                }
                if((y + s + 1) < n && x < n && (y + s + 1) >= 0 && x > -1){//inside the board for top
                    writeTreeTop(board, x, y, n, s);
                }
                for(int i = 1; i <= s; i++){
                    if((y + i) < n && x <= n && (y + i) >= 0 && x >= -1){//inside the board for trunk
                        writeTreeTrunk(board, x, y + i, n);
                    }
                }
            }
        }
        for(int i = 0; i < n + 2; i++){
            for(int j = 0; j < n + 2; j++)
                printf("%c",board[i][j]);
            printf("\n");
        }printf("\n");
    }
    return 0;
}