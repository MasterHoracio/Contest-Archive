#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int ai, bi;
}card;

bool cmp(card a, card b){
    if(a.bi > b.bi){
        return true;
    }else if(a.bi == b.bi){
        if(a.ai > b.ai)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

int main(){
    int n, points, indx, ans;
    card cards[1005];

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> cards[i].ai >> cards[i].bi;
    }

    sort(cards, cards + n, cmp);

    points = 1;
    ans = indx = 0;

    while(points >= 1 && indx < n){
        ans += cards[indx].ai;
        points += cards[indx++].bi;
        --points;
    }

    cout << ans << endl;

    return 0;
}