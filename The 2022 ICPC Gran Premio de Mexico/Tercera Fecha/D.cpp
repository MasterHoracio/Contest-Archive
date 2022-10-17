#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct point{
    int x, y;
};

int activate(int a, int b){
    return (a + b)/2;
}

int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    bool visited_x[1048577];
    int n, ans = 0, inf, sup, temp_mov1, temp_mov2;
    queue < pair<int, int> > Q_x;
    struct point goal, current;
    pair <int, int> temp;
    
    cin >> n >> goal.x >> goal.y;
    current.x = (int)pow(2, n-1);
    current.y = (int)pow(2, n-1);
    sup = (int)pow(2, n);
    inf = 0;
 
    //calcular todas las posibles formas de alcanzar a la partícula en el eje x (solo existe una posible solución)
    Q_x.push(make_pair(current.x, 0));
    visited_x[current.x] = true;
    while(!Q_x.empty()){
        temp = Q_x.front();
        Q_x.pop();
        if(temp.first == goal.x){
            ans = temp.second;
        }
        temp_mov1 = activate(temp.first, sup);
        temp_mov2 = activate(temp.first, inf);
        if(!visited_x[temp_mov1]){
            visited_x[temp_mov1] = true;
            Q_x.push(make_pair(temp_mov1, temp.second + 1));
        }
        if(!visited_x[temp_mov2]){
            visited_x[temp_mov2] = true;
            Q_x.push(make_pair(temp_mov2, temp.second + 1));
        }
    }
    
    cout << ans << endl;

    return 0;
}