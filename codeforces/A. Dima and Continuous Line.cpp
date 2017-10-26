#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int lef, rig;
}point;

bool cmp(point a, point b){
    return a.lef < b.lef;
}

bool intersect(point a, point b){
    if( (b.lef > a.lef && b.lef < a.rig) && (b.rig > a.rig || b.rig < a.lef) )
        return true;
    return false;
}

int main(){
    vector <point> plano;
    bool check = false;
    int n, num, mi, ma;
    point tmp;

    scanf("%d",&n);

    if(n <= 2){
        printf("no\n");
    }else{
        for(int i = 0; i < n; i++){
            scanf("%d",&num);
            if(i == 0){
                tmp.lef = num;
            }else{
                tmp.rig = num;
                mi = min(tmp.lef, tmp.rig);
                ma = max(tmp.lef, tmp.rig);
                tmp.lef = mi;
                tmp.rig = ma;
                plano.push_back(tmp);
                tmp.lef = num;
            }
        }

        sort(plano.begin(), plano.end(), cmp);

        for(int i = 0; i < plano.size() && !check; i++){
            for(int j = i + 1; j < plano.size() && !check; j++){
                if(intersect(plano[i], plano[j]))
                    check = true;
            }
        }

        (check) ? printf("yes\n") : printf("no\n");
    }

    return 0;
}